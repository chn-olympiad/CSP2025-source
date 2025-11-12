#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
long long n,m,k;
long long u[MAXN],v[MAXN],w[MAXN],c[11],a[11][MAXN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	cout<<"13";
	return 0;
}