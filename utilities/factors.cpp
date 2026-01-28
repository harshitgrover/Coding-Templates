// Functions for Factorization

vector<long long> primefactors(long long n, const vector<long long> & v) {
    vector<long long> f;
    for (auto & it : v) {
        if (it * it > n) break;
        while (n % it == 0) {
            f.push_back(it);
            n /= it;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

vector<long long> divs(long long n) {
    vector<long long> d;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i) d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}

vector<vector<long long>> nfactors(long long n) {
    vector<vector<long long>> w(n+1);
    for (long long i = 2; i < n+1; i++) {
        for (long long j = i; j <= n; j += i) {
            w[j].push_back(i);
        }
    }
    return w;
}

vector<vector<long long>> nprimefactors(long long n, vector<long long>& v) {
    vector<vector<long long>> w(n+1);
    for (auto & i : v) {
        for (long long j = i; j <= n; j += i) {
            w[j].push_back(i);
        }
    }
    return w;
}

