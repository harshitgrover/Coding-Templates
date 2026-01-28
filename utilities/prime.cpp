// Prime Functions

bool isprime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

vector<long long> genprime(long long limit) {
    vector<long long> pr;
    vector<bool> v(limit + 1, true);
    v[0] = v[1] = false;
    for (long long i = 2; i * i <= limit; i++) {
        if (v[i]) {
            for (long long j = i * i; j <= limit; j += i) v[j] = false;
        }
    }
    for (long long i = 2; i < limit + 1; i++) if (v[i]) pr.push_back(i);
    return pr;
}

vector<long long> genprimen(long long n) {
    vector<long long> primes;
    if (n == 0) return primes;
    long long limit = (n < 6) ? 15 : (long long)(n * log(n) + n * log(log(n)));
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i <= limit && primes.size() < n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= limit; j += i) is_prime[j] = false;
        }
    }
    return primes;
}

