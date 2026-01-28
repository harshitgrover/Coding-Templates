// Factorials and Inverse Factorials

vector<long long> modfac(long long n, long long mod) {
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (long long i = 1; i < n + 1; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    return fact;
}

vector<long long> imodfac(long long n, long long m1) {
    vector<long long> ifact(n + 1);
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (long long i = 1; i < n + 1; i++) fact[i] = (fact[i - 1] * i) % m1;
    ifact[n] = inv(fact[n], m1);
    for (long long i = n - 1; i > -1; i--) {
        ifact[i] = (ifact[i + 1] * (i + 1)) % m1;
    }
    return ifact;
}

