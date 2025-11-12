#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=550,mod=998244353;
int n,m,c[N];
string s;
int p[N],ans=0;
bitset <N> vis;
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++) if(s[i]=='1' && i-1-cnt<c[p[i]]) cnt++;
	return cnt>=m;
}
void dfs(int k,int o){
	p[k]=o;
	if(k==n){
		if(check()) ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			dfs(k+1,i);
			vis[i]=0;
		}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
//	f[0][0][0]=1;
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=i;j++){
//			for(int k=0;k<=i;k++){
//				f[i][j][k]=(f[i][j][k]+f[i-1][j][k])%mod;
//				if(i-1-j>=c[i] && k>0) f[i][j][k]=(f[i][j][k]+f[i-1][j][k-1])%mod;
//				if(i-j<c[i] && k>0 && j>0) f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k-1])%mod;
//				cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<"\n";
//			}
//		}
//	}
//	int ans=0;
//	for(int i=m;i<=n;i++) ans=(ans+f[n][i][cnt[1]])%mod;
//	for(int i=2;i<=n;i++)
//		for(int l=1,r=l+i-1;r<=n;l++,r++){
//			for(int k=l;k<r;k++)
//				f[l][r]
//		}
	dfs(0,0);
	cout<<ans;
	return 0;
}
/*
5 3
10101
6 0 4 2 1
*/
