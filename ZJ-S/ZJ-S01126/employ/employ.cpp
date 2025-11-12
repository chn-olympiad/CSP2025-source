#include<bits/stdc++.h>
#define ll long long
using namespace std;
int s[1010];
int a[1010];
const ll mod=998244353;
ll ans=0;
bool vis[1010];
int n,m;
int p[1010];
void dfs(int k){
	if(k==n+1){
		int la=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(la<a[p[i]]){
				if(s[i]==0){
					la++;
				}
				else{
					cnt++;
				}
			}
			else{
				la++;
			}
		}
		if(cnt>=m) ans=(ans+1)%mod;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[k]=i;
			dfs(k+1);
			vis[i]=0;
			p[k]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	bool p=1;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=c-'0';
		if(s[i]==0){
			p=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		if(p){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans<<'\n';
			return 0;
		}
		else{
			cout<<0<<'\n';
			return 0;
		}
	}
	else if(p){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
