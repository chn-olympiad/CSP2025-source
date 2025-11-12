#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,m,c[2010],vis[2010],mod=998244353;
ll ans;
string s;
void dfs(int d,int sum){
	if(d==n+1){
		ans=(ans+(n-sum>=m?1:0))%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int o=(s[d]=='0'||sum>=c[i]);
			dfs(d+1,sum+o);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	if(n<=18){
		dfs(1,0);
		cout<<ans<<endl;
	}else{
		
	}
	return 0;
}

