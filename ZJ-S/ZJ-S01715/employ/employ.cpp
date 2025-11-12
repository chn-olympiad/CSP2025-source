#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10;
const int mod=998244353;
int n,m,ans,flag,s;
int c[N],vis[N],f[N][N];
char op[N];
void dfs(int ts,int rs){
	if(rs>=m){
		int sum=1;
		for(int i=1;i<=n-ts+1;i++) sum=sum*i,sum%=mod;
		ans=(ans+sum)%mod; 
		return ;
	}
	if(n-ts+1+rs<m) return ;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(ts-rs-1>=c[i]||op[ts]=='0') dfs(ts+1,rs);
			else dfs(ts+1,rs+1);
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>op[i];
		if(op[i]=='0') flag=1;
		if(op[i]=='1') s++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m>s){
		cout<<0;
		return 0;
	}
	else if(n==m){
		if(flag==1) cout<<0;
		else{
			ans=1;
			for(int i=1;i<=n;i++) ans=ans*i,ans%=mod;
			cout<<ans;
		}
	}
	else{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}