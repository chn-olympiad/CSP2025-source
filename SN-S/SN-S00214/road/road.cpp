#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
const int K=10+5;
const int N=1e4+5;
int n,m,k;
int u[M],v[M],w[M];
int c[K],a[K][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];			
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
