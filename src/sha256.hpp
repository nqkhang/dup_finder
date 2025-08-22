#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <memory>
#include <openssl/evp.h>

namespace dup_finder {

struct OpenSSLDeleter {
    void operator()(EVP_MD_CTX* ctx) const {
        EVP_MD_CTX_free(ctx);
    }
};

using EvpMdCtxPtr = std::unique_ptr<EVP_MD_CTX, OpenSSLDeleter>;

bool sha256_file(const std::string& filename, std::string& hash) {
    EvpMdCtxPtr ctx(EVP_MD_CTX_new());
    if (!ctx) return false;

    if (EVP_DigestInit_ex(ctx.get(), EVP_sha256(), nullptr) != 1) {
        return false;
    }

    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }

    std::vector<unsigned char> buffer(32768);
    while (file.good()) {
        file.read(reinterpret_cast<char*>(buffer.data()), buffer.size());
        auto count = file.gcount();
        if (count > 0) {
            if (EVP_DigestUpdate(ctx.get(), buffer.data(), count) != 1) {
                return false;
            }
        }
    }

    unsigned char hash_value[EVP_MAX_MD_SIZE];
    unsigned int length_of_hash = 0;
    if (EVP_DigestFinal_ex(ctx.get(), hash_value, &length_of_hash) != 1) {
        return false;
    }

    std::stringstream ss;
    for (unsigned int i = 0; i < length_of_hash; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash_value[i]);
    }
    hash = ss.str();
    return true;
}

// int main() {
//     std::string hash;
//     if (sha256_file("test.txt", hash)) {
//         std::cout << "SHA-256: " << hash << std::endl;
//     } else {
//         std::cerr << "Hashing failed." << std::endl;
//     }
//     return 0;
// }   

} // namespace dup_finder 