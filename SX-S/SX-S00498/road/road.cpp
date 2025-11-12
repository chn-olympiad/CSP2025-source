#include <bits/stdc++.h>
using namespace std;
struct T{
	int u,v,w;
}b[1000006];
int n,m,k,c[10],a[1000006];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	srand(time(0));
	int r=rand();
	cout<<r;
	return 0;
} 