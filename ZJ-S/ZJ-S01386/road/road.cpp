#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10001],v[10001],w[1000001];
//k = 0,m = 1000000;n = 10000;
int ans = 0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <= m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans += w[i];
	}
	int maxx = -1;
	for(int i = 1;i <= m;i++){
		maxx = max(maxx,w[i]);
	}
	cout<<ans - maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
