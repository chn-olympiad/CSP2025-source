#include <bits/stdc++.h>
using namespace std;
#define int long long
int ara[5005];
int nn,anss;
int dfs(int posi,int lens,int nu,int mm,bool fl) {
	if(nu>=3&&nu<=nn&&fl) {
		if(lens>2*mm) {
			anss++;
		}
		anss%=998244353;
	}
	if(posi>nn) return 0;
	dfs(posi+1,lens,nu,mm,false);
	dfs(posi+1,lens+ara[posi],nu+1,max(mm,ara[posi]),true);
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>nn;
	for(int i=1; i<=nn; i++) {
		cin>>ara[i];
	}
	dfs(1,0,0,0,false);
	cout<<anss%998244353;
	return 0;
} 
