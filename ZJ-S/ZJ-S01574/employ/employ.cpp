#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[510],flagA=1,ans,mod=998244353;
string s;
int x[20],vis[20];
void dfs(int t){
	if(t>n){
		int lose=0,win=0;
		for(int i=1;i<=n;i++){
			if(lose<c[x[i]]&&s[x[i]-1]=='1'){
				win++;
			}else{
				lose++;
			}
		}
		if(win>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			x[t]=i;
			dfs(t+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		cout<<0;
	}else{
		dfs(1);
		cout<<ans;
	}
	return 0;
}
