#include<bits/stdc++.h>
using namespace std;
bool s[505],vis[505];
char ch;
long long c[505],ans,n,m;
void dfs(long long now,long long cnt){
	if(now==n+1){
		if(n-cnt>=m)
			ans=(ans+1)%998244353;
		return;
	}
	for(long long i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			if(c[i]<=cnt||s[now]==0)
				dfs(now+1,cnt+1);
			else
				dfs(now+1,cnt);
			vis[i]=0;
		}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>ch;
		s[i]=ch-'0';
	}
	for(long long i=1;i<=n;i++)
		cin>>c[i];
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
