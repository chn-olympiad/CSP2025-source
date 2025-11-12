#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+10;
/*
4 4 2 
1 4 6
2 3 7
4 2 5 
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

int n,m,k,ans;
int u[mx],v[mx],w[mx];
int c[mx],a[mx][4];
int li[mx];
//已连接 li[i]表示第i城市是否连接 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for(int i=0;i<m;i++){
		cin >>u[i]>>v[i]>>w[i];
		//    城1   城2   价格 
	} 
	
	for(int i=0;i<k;i++){
		cin >>c[i];
		for(int j=1;j<=n;j++) cin >>a[i][j];
		//   修价格   城1    2           3      4 
	}
	
	for(int j=0;j<k;j++){
		int cost_j=c[j];
		for(int i=0;i<n;i++){
			int ct1=u[i],ct2=v[i];
			cost_j+=a[j][ct1];
			cost_j+=a[j][ct2];
			if(li[ct1]!=1&&li[ct2]!=1)
				ans+=min(w[i],cost_j);
			cost_j = cost_j - a[j][ct1]-a[j][ct2];
			li[ct1]=1;
			li[ct2]=1;
		}
	}
	
	cout <<ans;
	
	return 0;
}
