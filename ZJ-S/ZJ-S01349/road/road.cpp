#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10001][10001];
int v[11][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int p,q;
		cin>>p>>q;
		cin>>a[p][q];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>v[i][j];
		}
	}
	int d;
	for(int i=1;i<=n;i++){
		d+=v[1][i];
		cout<<d;
	}
}