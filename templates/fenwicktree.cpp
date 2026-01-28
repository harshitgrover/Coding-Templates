// Fenwick Tree (Binary Indexded Tree)

struct fenwicktree {
    long long n;
    vector<long long> bit;

    fenwicktree(vector<long long> &a) : n(a.size()), bit(n + 1, 0) {
        for (long long i = 1; i <= n; i++) {
            bit[i] += a[i - 1];
            long long j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    fenwicktree(long long n1) : n(n1), bit(n1 + 1, 0) {}

    void upd(long long i, long long x) {
        for (i++; i <= n; i += i & -i) bit[i] += x;
    }

    long long query(long long i) {
        long long s = 0;
        for (i++; i > 0; i -= i & -i) s += bit[i];
        return s;
    }

    long long query(long long l, long long r) {
        return query(r) - query(l - 1);
    }

    long long find_kth(long long k) {
        long long idx = 0;
        for (long long i = 1 << (long long)log2(n); i > 0; i >>= 1) {
            if (idx + i <= n && bit[idx + i] < k) {
                idx += i;
                k -= bit[idx];
            }
        }
        return idx;
    }
};
