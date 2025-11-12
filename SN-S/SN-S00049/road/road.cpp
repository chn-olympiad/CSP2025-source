#include <bits/stdc++.h>
using namespace std;
int n,m,k,u1[1000000],u2[1000000],w[1000000],c[10000][10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u1[i]>>u2[i]>>w[i];
	}
	for(int i=0;i<=k;i++){
		for(int j=0;j<n;j++){
			cin>>c[j][i];
		}
	}
		
}
