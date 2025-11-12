#include<bits/stdc++.h>
using namespace std;
int n,m,ans,p[15],c[505];
string s;
bool vis[15];
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[p[i]]){cnt++;continue;}
		if(s[i-1]=='0'){cnt++;continue;}
	}
	return n-cnt>=m;
}
void dfs(int x){
	if(x>n){
		if(check())ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		p[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n>10)solve();
	dfs(1);
	cout<<ans;
	return 0;
}
