#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,k;
int jxh=-1;
bool vis[N];
struct node {
	int u,v,w,c;
} a[N];
int g[N];
int cnt=2e9+9;
int x=0;
void dfs(int no,int ans,int si,int kx){
//	cout<<no<<" "<<si<<" "<<ans<<" "<<cnt<<" "<<g[no]<<" "<<n+kx<<endl;

	if(si>=n+kx-1){
		cnt=min(cnt,ans);
		return;
	}
	
	for(int i=1;i<=m+k+x;i++){
		if(a[i].u==no&&vis[i]==0){
			vis[i]=1;
			dfs(a[i].v,ans+a[i].w,si+1,kx);
			vis[i]=0;
		}

		if(a[i].v==no&&vis[i]==0){
			vis[i]=1;
			dfs(a[i].u,ans+a[i].w,si+1,kx);
			vis[i]=0;
		}
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		g[i]=-1;
		a[i].c=-1;
	}
	
	for(int i=1; i<=k; i++) {
		cin>>g[m+i];
		a[i+m+x+1].c=g[i+m+x+1];
		for(int j=1;j<=n;j++){
			a[i+j+m+x].v=j;
			a[i+j+m+x].u=i+m;
			cin>>a[i+j+m+x].w;
		}
		x+=n;
	}
//	for(int i=1;i<=m+k+x;i++){
//		cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<" "<<g[i]<<"\n";
//	}
	for(int i=1;i<=n;i++){
		dfs(i,0,0,0);
//		cout<<"***---***\n";
	}
	
	
//	int zc;
//	cin>>zc;
//	cout<<g[zc]<<endl;
	cout<<cnt;
return 0;}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
