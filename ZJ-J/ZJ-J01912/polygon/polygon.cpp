#include<bits/stdc++.h>
using namespace std;
int n,i,res;
int a[5005];
bool vis[5005];
void dfs(int dep,int co,int e){
	if(co>a[i]){
		for(int j=1;j<i;j++){
			if(vis[j]==1)cout<<a[j]<<" ";
		}cout<<a[i]<<endl;
		res++;
	}
	if(dep==e)return;
	vis[dep]=1;
	dfs(dep+1,co+a[dep],e);
	vis[dep]=0;
	dfs(dep+1,co,e);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int k=1;k<=n;k++){
		cin>>a[k];
	}
	sort(a+1,a+n+1);
	int cs=0;
	
	for(i=3;i<=n;i++){
		for(int v=1;v<=n;v++)vis[v]=0;
		dfs(1,0,i);
	}cout<<res%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}