#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int a[11][10001],n,m,k;
struct Edge{
	int fr,to,w;
}e[1000001];
long long cnt;
bool flag[10001];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=10;i++){
		for(int j=0;j<=10000;j++){
			a[i][j]=inf;
		}
	}
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].fr>>e[i].to>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			if(a[j][e[i].fr]+a[j][e[i].to]+a[j][0]<=e[i].w){
				e[i].w=a[j][e[i].fr]+a[j][e[i].to]+a[j][0];
				a[j][e[i].fr]=0;
				a[j][e[i].to]=0;
				a[j][0]=0;
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(flag[e[i].fr]==0||flag[e[i].to]==0){
			cnt+=e[i].w;
			flag[e[i].fr]=1;
			flag[e[i].to]=1;
		}
	}
	cout<<cnt;
	return 0;
}
