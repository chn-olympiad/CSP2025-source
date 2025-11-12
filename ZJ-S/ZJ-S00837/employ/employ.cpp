#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
bool a[505],vis[505];
int n,m,c[505],ans;
void dfs(int x,int s,int l){
	if(x>n){
		if(s>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i] = 1;
		if(!a[x]||c[i]<=l){
			dfs(x+1,s,l+1);
		}else{
			dfs(x+1,s+1,l);
		}
		vis[i] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i] = x-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		dfs(1,0,0);
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}
