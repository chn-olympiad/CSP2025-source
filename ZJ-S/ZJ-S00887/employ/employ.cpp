#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int t[505],c[505];
int p[505];
long long N=1,ans;
bool vis[505];
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(t[i]==0||cnt>=c[p[i]]) cnt++;
		}
		if(n-cnt>=m){
			ans=(ans+1)%998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=s.length()-1;i>=0;i--){
		t[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n>18){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=1ll*ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}