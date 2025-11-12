#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,s[505],c[505],e[505];
bool vis[505];
ll ans;
void dfs(int x,int now){
	if(n-now<m) return;
	if(x>n){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			e[x]=i;
			if(s[x]==0||now>=c[i]) dfs(x+1,now+1);
			else dfs(x+1,now);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char x;
	for(int i=1;i<=n;i++){
		cin>>x;
		s[i]=x-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
}
