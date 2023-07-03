#ifndef _RSA_UTIL_H_
#define _RSA_UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

int encrypter_init();
int encrypt_path(const char *path, size_t pathsize);
const char * decrypt_path();
int encrypter_deinit();

#ifdef __cplusplus
}
#endif

#endif