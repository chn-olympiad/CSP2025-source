#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
mt19937_64 rnd(time(0));
inline int gen(int l,int r){
	return l+rnd()%(r-l+1);
}
int main(){
	freopen("road.in","w",stdout);
	int n=gen(1,100),m=gen(n-1,300),k=gen(5,10);
    cout<<n<<' '<<m<<' '<<k<<'\n';
    m-=n-1;
    rep(i,2,n) cout<<gen(1,i-1)<<' '<<i<<' '<<gen(0,1e9)<<'\n';
    rep(i,1,m){
        int u=gen(1,n),v=gen(1,n);
        while (u==v) u=gen(1,n),v=gen(1,n);
        cout<<u<<' '<<v<<' '<<gen(0,1e9)<<'\n';
    }
    rep(i,1,k){
        rep(j,1,n) cout<<gen(0,1e9)<<' ';
        cout<<'\n';
    }
}