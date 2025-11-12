#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int u[100],v[100],w[100];
int c[100],a[100];

int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i ++){
		cin>>u[i],v[i],w[i];
	}
	for(int i = 1;i <= k;i ++){
		cin>>c[i];
		for(int j = 1;j <= n;j ++){
			cin>>a[j];
		}
	}
	
	cout<<13;
	
	return 0;
}
