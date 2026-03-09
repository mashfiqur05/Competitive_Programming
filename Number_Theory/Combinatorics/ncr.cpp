#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
const long long MOD = 1e9+7;

long long fact[N],invfact[N];

long long power(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

void precompute(){
    fact[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=fact[i-1]*i%MOD;

    invfact[N-1]=power(fact[N-1],MOD-2);

    for(int i=N-2;i>=0;i--)
        invfact[i]=invfact[i+1]*(i+1)%MOD;
}

long long nCr(int n,int r){
    if(r>n) return 0;
    return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
}

int32_t main()
{
    precompute();

    cout << nCr(10,3);

    return 0;
}