// Exponentiation/power functions with modular arithemetic

long long pow(long long a,long long b){
    long long res=1;
    while(b>0){
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

long long modpow(long long a,long long b,long long m){
    long long res=1;
    while(b){
        if(b&1) res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}

long long inv(long long a,long long m){
    return modpow(a,m-2,m);
}
