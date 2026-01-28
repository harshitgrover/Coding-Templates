// Generic Segment Tree with Lazy Propogation

template<typename Node, typename Update>
struct LazySGT {
    vector<Node> tree;
    vector<bool> lazy;
    vector<Update> updates;
    vector<long long> arr; // type may change
    long long n;
    long long s;
    LazySGT(vector<long long> &a) { // change if type updated
        arr = a;
        n = a.size();
        s = 1;
        while(s < 4 * n){
            s = s << 1;
        }
        tree.resize(s); fill(tree.begin(), tree.end(), Node());
        lazy.resize(s); fill(lazy.begin(), lazy.end(), false);
        updates.resize(s); fill(updates.begin(), updates.end(), Update());
        build(0, n - 1, 1);
    }
    LazySGT(long long _n) {
        n = _n;
        s = 1;
        while(s < 4 * n){
            s = s << 1;
        }
        tree.resize(s); fill(tree.begin(), tree.end(), Node());
        lazy.resize(s); fill(lazy.begin(), lazy.end(), false);
        updates.resize(s); fill(updates.begin(), updates.end(), Update());
    }
    void build(long long start, long long end, long long index) { // Never change this
        if (start == end)   {
            tree[index] = Node(arr[start]);
            return;
        }
        long long mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void pushdown(long long index, long long start, long long end){
        if(lazy[index]){
            long long mid = (start + end) / 2;
            apply(2 * index, start, mid, updates[index]);
            apply(2 * index + 1, mid + 1, end, updates[index]);
            updates[index] = Update();
            lazy[index] = 0;
        }
    }
    void apply(long long index, long long start, long long end, Update& u){
        if(start != end){
            lazy[index] = 1;
            updates[index].combine(u, start, end);
        }
        u.apply(tree[index], start, end);
    }
    void update(long long start, long long end, long long index, long long left, long long right, Update& u) {  // Never Change this
        if(start > right || end < left)
            return;
        if(start >= left && end <= right){
            apply(index, start, end, u);
            return;
        }
        pushdown(index, start, end);
        long long mid = (start + end) / 2;
        update(start, mid, 2 * index, left, right, u);
        update(mid + 1, end, 2 * index + 1, left, right, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(long long start, long long end, long long index, long long left, long long right) { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right){
            return tree[index];
        }
        pushdown(index, start, end);
        long long mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(long long left, long long right, long long val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, left, right, new_update);
    }
    Node make_query(long long left, long long right) {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1 {
    long long val; // may change
    Node1() { // Identity element
        val = 0;    // may change
    }
    Node1(long long p1) {  // Actual Node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r) { // Merge two child nodes
        val = l.val + r.val;  // may change
    }
};

struct Update1 {
    long long val; // may change
    Update1(){ // Identity update
        val = 0;
    }
    Update1(long long val1) { // Actual Update
        val = val1;
    }
    void apply(Node1 &a, int start, int end) { // apply update to given node
        a.val = val * (end - start + 1); // may change
    }
    void combine(Update1& new_update, int start, int end){
        val = new_update.val;
    }
};
