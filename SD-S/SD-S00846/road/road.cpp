#include<bits/stdc++.h>
using namespace std;
#define long long int
const int N=1e7+5;
int n,m,k,u,v,w;
int fs[N][3];
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int cnt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>fs[i][j];
			cnt=max(cnt,fs[i][j]);
		}
	}
	for(int i=m+1;i<=m+k+1;i++){
		for(int j=1;j<=n+1;j++){
			cin>>fs[i][j];
			cnt=max(cnt,fs[i][j]);
		}
	}
	cout<<cnt;
	return 0;
}

