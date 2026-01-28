// Disjoint Set Union
// DSU with union by rank and path compression

class disjointset{
    vector<long long> rank,parent,sz;
public:
    disjointset(long long n){
        rank.resize(n+1);
        parent.resize(n+1);
        sz.resize(n+1,1);
        for(long long i=0;i<n+1;i++) parent[i]=i;
    }
    long long findp(long long node){
        return node==parent[node]?node:parent[node]=findp(parent[node]);
    }
    void unionr(long long u,long long v){
        long long pu=findp(u),pv=findp(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) parent[pu]=pv,sz[pv]+=sz[pu];
        else if(rank[pv]<rank[pu]) parent[pv]=pu,sz[pu]+=sz[pv];
        else parent[pv]=pu,sz[pu]+=sz[pv],rank[pu]++;
    }
    long long getsize(long long u){
        return sz[findp(u)];
    }
    bool iscon(long long u,long long v){
        return findp(u)==findp(v);
    }
    vector<long long> getrank(){
        return rank;
    }
    long long countsets(long long j){
        long long ans=0;
        for(long long i=j;i<(long long)parent.size()-1+j;i++) if(parent[i]==i) ans++;
        return ans;
    }
};
