#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
mt19937_64 rnd(time(0));
inline int gen(int l,int r){
	return l+rnd()%(r-l+1);
}
int main(){
	freopen("club.in","w",stdout);
	int t=10;
	cout<<t<<'\n';
	while (t--){
		int n=gen(1,5)*2;
		cout<<n<<'\n';
		rep(i,1,n) cout<<gen(0,5)<<' '<<gen(0,5)<<' '<<gen(0,5)<<'\n';
	}
}