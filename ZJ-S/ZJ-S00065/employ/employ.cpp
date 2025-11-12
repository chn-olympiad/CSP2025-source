#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[1005],b[1005],c[1005],vis[1005];
void check(){
	int sum=0,lst=0;
	for(int i=1;i<=n;i++){
		int now=a[i];
		if(b[i]==0||lst>=c[now]){
			lst++;
		}
		else{
			sum++;
		}
	}
	ans+=(sum>=m);
}
void dfs(int x){
	if(x>n){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1,a[x]=i;
		dfs(x+1);
		vis[i]=0,a[x]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		b[i]=ch-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}