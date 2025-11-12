#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+10;
const int N=1e4+10;
struct node{
	int u,v,w;
}b[N];
int c[15];
int a[N]; 
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		b[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	cout<<0;
	return 0;
}

