#include<bits/stdc++.h>
using namespace std;
int a[10015][10005]={-1};
int b[15][10005];
int ans=0;
vector<int> landed(100015,0);
void find(int n,int res,int t){
	if(res>ans or landed[n]!=0){
		return;
	}
	int a=0;
	for(int j=1;j<=n;j++){
		if(landed[j]!=0){
			a=1;
		}else{
			a=0;
			break;
		}
	}
	if(a==1){
		if(res<ans){
			ans=res;
			return ;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==n){
			continue;
		}
		if(a[n][i]!=-1){
			res+=a[n][i];
			landed[n]=114;
			find(n+1,res,t);
			landed[n]=0;
			res-=a[n][i];
		}
	}
	return ;	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	find(1,0,n);
	cout<<ans<<endl;
	return 0;
}
