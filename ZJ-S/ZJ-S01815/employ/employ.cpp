#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int ans;
int vis[N];
int s[N],c[N];
int n,m;
void dfs(int d,int x,int r,int h){
	if(!s[d]||r>=c[x])r++;
	else h++;
	if(d==n&&h>=m){
		ans=(1ll*ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(d+1,i,r,h);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s1;cin>>s1;
	for(int i=1;i<=n;i++){
		s[i]=s1[i-1]-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,i,0,0);
		vis[i]=0;
	}
	cout<<ans<<endl;
	return 0;
}
