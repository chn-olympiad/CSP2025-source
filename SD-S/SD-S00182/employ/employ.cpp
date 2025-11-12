#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,c[20010],res,vis[20010],t[20010];string s;
void dfs(int u,int num){
	if(num>n-m)return;
	if(u>n)res++;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		t[u]=i;
		if(s[u-1]=='0'||c[t[u]]<=num)dfs(u+1,num+1);
		else dfs(u+1,num);
		vis[i]=0; 
	}
}
signed main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0);
	cout<<res; 
	return 0;
}
