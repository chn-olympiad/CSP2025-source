#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,a[510],ans,vis[510];
char ch[510];
void dfs(ll lx,ll lf){
	if(lx>n){
		if(n-lf>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			if(lf>=a[i]||ch[lx]=='0') dfs(lx+1,lf+1);
			else dfs(lx+1,lf);
			vis[i]=0;
		}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>ch[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=12){
		dfs(1,0);
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==0||ch[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=2;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
	}
	return 0;
}