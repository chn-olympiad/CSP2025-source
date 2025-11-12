#include <bits/stdc++.h>
using namespace std;
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,minf,b;
	cin>>n>>m>>k;
	int a[n],w[k];
	for(int i;i<3*n;i++){
		cin>>a[n];
	}
	for(int i;i<4*k;i++){
	cin>>w[k];
	}	
	for(int i;i<k;i++){
	minf=a[n]+w[k];
	b=b+minf;
	}
	b=b-1;
	cout<<b;
	return 0;
}

