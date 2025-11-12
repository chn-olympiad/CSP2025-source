#include<bits/stdc++.h>
using namespace std;
const int MODme=998244353;
int n,anser;
int a[5005];
bool vis[5005];
map<string,int>visit;
void dfs(int i,int sum,int lend){
	if(sum<3)return;
	int maxx=0;
	string ssum="";
	for(int j=1;j<=n;j++){
		if(vis[j]){
			maxx=max(maxx,a[j]);
			ssum=sum+j;
		}
	}
	if(visit[ssum]==1)return;
	visit[ssum]=1;
	if(lend>maxx*2)anser=(anser+1)%MODme;
	for(int j=1;j<=n;j++){
		if(vis[j]){
			vis[i]=0;
			dfs(j,sum-1,lend-a[i]);
			vis[i]=1;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int lend=0,maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lend+=a[i];
		maxx=max(maxx,a[i]);
	}
	//memset(vis,1,sizeof vis);
	//dfs(0,n,lend);
	if(lend>maxx*2)anser++;
	cout<<anser;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
