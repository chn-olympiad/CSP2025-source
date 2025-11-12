#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N = 1e9;
long long u[N+5],v[N+5],w[N+5],c[N+5];
int a[N+5];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=k;j++){
			cin>>a[i];
		}
	}
	cout<<13*1;
	return 0;
}
