#include <bits/stdc++.h>
#define int long long
using namespace std;
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
const int N=500,Mod=998244353;
int n,m;
int sum[N];
int c[N];
int d[N];
bool Y[N];
int ans=0;
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
void dfs(int x,int y){
	if(x==n+1){
		if(n-y>=m) {
			ans++;
			ans%=Mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(Y[i]) continue;
		Y[i]=1;
		d[x]=i;
		int ny=y;
		if(y>=c[i] || sum[x]==0) ny++; 
		dfs(x+1,ny);
		Y[i]=0;
	}
}
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;cin>>x;
		if(x=='1') sum[i]++;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/