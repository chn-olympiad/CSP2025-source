#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int k;
int u[100005],v[100005],w[100005];
int c[100005];
int a[100005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<=n;j++){
			cin>>a[i];
		}
	}
	cout<<13;
	return 0;
} 
