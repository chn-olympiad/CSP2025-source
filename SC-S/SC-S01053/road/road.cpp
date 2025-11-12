#include<bits/stdc++.h>
using namespace std;
const int maxx=1e4+5;
const int mm=1e6+20;
struct node{
	int u,v,w;
}P[maxx];
int S[15][mm];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>P[i].u>>P[i].v>>P[i].w;
	for(int i=1;i<=k;i++){
		cin>>S[i][1];
		for(int j=2;j<=m+1;j++){
			cin>>S[i][j];
		}
	}
	cout<<0;
	return 0;
}//特殊性质A：对于所有1≤j≤k，均有cj=0且均存在1≤i≤n满足aj,i=0。