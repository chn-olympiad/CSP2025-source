#include<bits/stdc++.h>
using namespace std;
const int N=100010;
const int M=10010;
int T,n,m,k;
int sum[M][M]={0};
struct city{
	int u,w,v;
}a[N];
struct country{
	int js,lj;
}b[N];
int cnt[M][M]={-1};
vector<int>ll;
void dfs(int x){
	for(int i=1;i<=x;i++){
		for(int j=x;j<=1;i--){
			
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a[1].w,a[m+1].w);
	for(int i=1;i<=k;i++){
		cout<<a[i].u<<a[i].v<<a[i].w;
		cin>>b[i].js;
		for(int j=1;j<=n;j++){
			cin>>b[j].lj;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}