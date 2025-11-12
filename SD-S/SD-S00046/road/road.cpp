#include<bits/stdc++.h>
#define int long long
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define endl '\n'
using namespace std;

const int N=1000556;

int n,m,k;int u[N],v[N],w[N];
int c[20][N],f[3000][3000];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	FILE("road")
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	
	
	return 0;
}
