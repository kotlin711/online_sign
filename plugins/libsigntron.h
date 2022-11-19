#ifdef __cplusplus
extern "C" {
#endif
extern char* tron_easy_transfer_usdt(char* key, char* toAddress, long long int amount);
extern char* tron_easy_transfer(char* key, char* toAddress, long long int amount);
extern char* tron_transaction_sign_trc10(char* jsonstr, char* key);
extern char* tron_transaction_sign_trc20(char* jsonstr, char* key);
#ifdef __cplusplus
}
#endif
