#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
struct ordered_multiset {
    using ost = tree<pair<T,long long>, null_type, less<pair<T,long long>>,
                     rb_tree_tag, tree_order_statistics_node_update>;
    ost s;
    long long idx = 0;

    void insert(T x) {
        s.insert({x, idx++});
    }
    void erase(T x) {
        auto it = s.lower_bound({x, -1});
        if (it != s.end() && it->first == x)
            s.erase(it);
    }
    long long order_of_key(T x) {
        return s.order_of_key({x, -1});
    }
    T find_by_order(long long k) {
        return s.find_by_order(k)->first;
    }
    long long size() {
        return (long long)s.size();
    }
    bool empty() {
        return s.empty();
    }
};
