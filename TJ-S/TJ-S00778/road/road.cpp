#include<bits/stdc++.h>
using namespace std;
int a[17];
int u[10007];
int v[1000007];
int w[1000007];
int c[1000107],x[1000107];
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum = 0;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	sort(w+1,w+1+n);
	int h = 1,x[17];
	for(int i=1;i<=k;i++){
		cin >> a[i];
		for(int j=1;j<=n;j++){
			cin >> c[i];
			x[h] = c[i];
			h++;
		}
	}
	sort(a+1,a+1+k);
	sort(x+1,x+1+n*k);
	for(int i=1;i<=k;i++){
		sum+=c[i];
		sum+=w[i];
	}
	cout << sum+a[1];
	
	return 0;
}
