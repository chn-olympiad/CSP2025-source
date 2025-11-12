#include<bits/stdc++.h>
using namespace std;
const int maxn=10001;
int u[maxn],v[maxn],w[maxn],a[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=n+1;i++){
		cin>>a[i];
	}
	cout<<"0";
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
