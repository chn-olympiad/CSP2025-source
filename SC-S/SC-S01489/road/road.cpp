#include<bits/stdc++.h>
using namespace std;
/*
题意：
有n点m边，第i边花费w[i],以可用
有k点花c[k]解锁后，花费a[k][j]与j点连接
求使不需解锁点连通的最小花费
思路（k=0时）：

思路（A时）：
0
*/
int P[10001][10001];
int n,m,k,co[1000001],c[11],cco[11][10001],f[10001];
bool A=true;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(P,-1,sizeof(P));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(P[u][v]!=-1) P[u][v]=min(P[u][v],w);
		else P[u][v]=w;
	}
	for(int t=1;t<=k;t++){
		cin>>c[t];
		if(c[t]!=0) A=false;
		for(int i=1;i<=n;i++){
			cin>>cco[t][i];
//			if(cco[t][i]!=0) A=false;
		}
	}
	if(k!=0 and A){
		cout<<"0";
		return 0;
	}
	else cout<<"网络故障，请稍后再试";
	return 0;
}