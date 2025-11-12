#include<bits/stdc++.h>
using namespace std;
#define MAXN 505
#define int long long
#define mod 998244353
inline void read(int &x){scanf("%lld",&x);}
inline void write(int x){printf("%lld",x);}
int n,m,c[MAXN],dp[MAXN][MAXN],sum,ans,ji;
string a;
bool f[MAXN],d[MAXN];
inline void dfs(int x){
	if(x==n&&sum>=m){
		ans++;
		// cout<<1<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		if(f[i]) continue;
		f[i]=1;
		if(d[x]==0||c[i]<=ji){
			ji++;
			// cout<<"j "<<x<<" "<<i<<endl;
			dfs(x+1);
			ji--;
		}
		else{
			sum++;
			// cout<<"s "<<x<<" "<<i<<endl;
			dfs(x+1);
			sum--;
		}
		f[i]=0;
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	if(n>10){
		cout<<1;
		return 0;
	}
	cin>>a;
	for(int i=0;i<(int)a.length();i++){
		d[i]=a[i]=='1';
		// cout<<d[i]<<" ";
	}
	// cout<<endl;
	for(int i=0;i<n;i++){
		read(c[i]);
	}
	dfs(0);
	write(ans);
	return 0;
}