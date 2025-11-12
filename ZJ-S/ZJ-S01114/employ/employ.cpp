#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],vis[505],a[505],cnt;
string s;
void dfs(int k,int tot){
	if(k>n){
		if(n-tot>=m)++cnt;
		return ;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		int tmp=tot;
		if(c[i]<=tot||s[i]=='0')++tmp;
		vis[i]=1;a[k]=i;
		dfs(k+1,tmp);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0);
	cout<<cnt;
	return 0;
}
/*
3 2
101
1 1 2

*/
