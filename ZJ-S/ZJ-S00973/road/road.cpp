#include<bits/stdc++.h>
using namespace std;
long long a[10020][10020]= {0},b[20]= {0},c[10020]= {0},ad[10020]= {0};
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	memset(a,-1,sizeof(a));
	memset(c,LONG_MAX,sizeof(c));
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1; i<=k; i++) {
		cin>>b[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i+n][j];
			a[j][i+n]=a[i+n][j];
		}
	}
	queue<int>q;
	q.push(1);
	c[1]=0;
	while(!q.empty()) {
		int d=q.front();
		q.pop();
		for(int i=1; i<=n; i++) {
			if(a[d][i]!=-1) {
				if(c[d]+a[d][i]<c[i]) {
					q.push(i);
					c[i]=c[d]+a[d][i];
					ad[i]=a[d][i];
				}
			}
		}
		if(d>n) {
			continue;
		}
		for(int i=1; i<=k; i++) {
			if(a[d][i+n]!=-1) {
				if(c[d]+a[d][i+n]+b[i]<c[i+n]) {
					q.push(i);
					c[i]=c[d]+a[d][i+1]+b[i];
					ad[i]=a[d][i+1]+b[i];
				}
			}
		}
	}
	long long res=0;
	for(int i=1; i<=n+k; i++) {
		res+=ad[i];
	}
	cout<<res;
	return 0;
}
