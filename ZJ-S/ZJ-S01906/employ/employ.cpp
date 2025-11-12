/*
ji le
man da man suan fen shu zhi you 216
xi wang neng you 1=
wo qiu ni le
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,k,c[505],ans,f[505],v[55],sum,p[55];
string s;
void dfs(int x,int suc,int fal){
	if(n-fal<m) return;
	if(n-x+1+suc<m) return;
	if(x==n+1){
		if(suc>=m){
//			for(int i=1;i<=n;i++) cout<<p[i]<<' ';
//			cout<<endl;
			ans++,ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]!=0) continue;
		p[x]=i;
		if(s[x-1]=='0'||c[i]<=fal){
			v[i]=-1;
			dfs(x+1,suc,fal+1);
			v[i]=0;
		}else{
			v[i]=1;dfs(x+1,suc+1,fal);v[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) if(s[i]=='1') k++;
	f[0]=1;for(int i=1;i<=n;i++) f[i]=f[i-1]*i%mod;
	for(int i=1;i<=n;i++) cin>>c[i],sum+=(c[i]==0);
	sort(c+1,c+n+1);
	if(m==n){
		if(sum>0) cout<<0<<endl;
		else cout<<f[n]<<endl;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
