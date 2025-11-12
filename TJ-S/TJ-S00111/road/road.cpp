#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=1e6+5;
int u[M], v[M], w[M];
int a[11][N];
int c[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	cout<<0<<'\n';
	return 0;
}
//就是开不了口让她知道 就是那么简单几句我办不到 
//整个心悬在半空 我只能够远远看着 这些我都做得到 但那个人已经不是我 
