#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c[505],b[505],ans=0;
bool vis[505];
string s;
void dfs(ll x){
	if(x>n){
		int cnt=0,sum=0;
		for(ll i=1;i<=n;i++){
			if(cnt>=b[i]){
				cnt++;
			}else{
				if(s[i-1]=='1'){
					sum++;
				}else{
					cnt++;
				}
			}
		}
		if(sum>=m){
			ans++;
		}
		return;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		b[x]=c[i];
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(vis,0,sizeof vis);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}