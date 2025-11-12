#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
long long ans;
int vis[N],c[N],s[N];
void dfs(int d,int p,int r){
	int res=0;
	if(d==1+n){
		if(n-r<=m) ans++;
	}
	if(r>=c[p]) return ;
	if(s[d]) res=1;
	for(int i=1;i<=n;i++){
		if(vis[i]||i==p) continue;
		vis[i]=1;
		dfs(d+1,i,r+res);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string qwe;
	cin>>qwe;
	for(int i=1;i<=n;i++){
		s[i]=qwe[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		
		dfs(1,i,0);
	}
	cout<<ans;
	return 0;
}
