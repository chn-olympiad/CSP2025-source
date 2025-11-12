#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[100005];
int vis[100];
int p[100];
long long dfs(int u){
	if(u==n+1){
		int cnt=0,g=0;
		for(int i=1;i<=n;i++){
			if(c[p[i]]<=g||s[i]=='0')g++;
			else cnt++;
		}
		if(cnt>=m)return 1;
		return 0;
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[u]=i;
			cnt+=dfs(u+1);
			vis[i]=0;
		}
	}
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	s=" "+s;
	if(m==n){
		int flag=1;
		for(int i=1;i<=n;i++)if(s[i]=='0'||c[i]==0)flag=0;
		if(flag){
			long long ans=1;
			for(int i=1;i<=n;i++)ans*=i,ans%=mod;
			cout<<ans<<endl;
		}
		else cout<<0;
		return 0;
	}
	cout<<dfs(1);
	return 0;
}

