#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,f[405][405][405];
struct node {
	int yi,er,san;
} d[N];
bool cmp(node a,node b){
	return a.yi>b.yi;
}
void solve() {
	sort(d+1,d+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=d[i].yi;
	}
	cout<<ans<<'\n';
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--) {
		cin>>n;
		int ans=0,vis=0;
		for(int i=1; i<=n; i++) {
			cin>>d[i].yi>>d[i].er>>d[i].san;
			if(d[i].er!=0||d[i].san!=0)vis=1;
		}
		if(!vis) {
			solve();
			continue;
		}
		memset(f,0,sizeof f);
		for(int i=0; i<=n/2; i++) {
			for(int j=0; j<=n/2; j++) {
				for(int k=0; k<=n/2; k++) {
					if(i)f[i][j][k]=max(f[i-1][j][k]+d[i+j+k].yi,f[i][j][k]);
					if(j)f[i][j][k]=max(f[i][j-1][k]+d[i+j+k].er,f[i][j][k]);
					if(k)f[i][j][k]=max(f[i][j][k-1]+d[i+j+k].san,f[i][j][k]);
				}
			}
		}
		for(int i=1; i<=n/2; i++) {
			for(int j=1; j<=n/2; j++) {
				ans=max(ans,f[i][j][n-i-j]);
			}
		}
		cout<<ans<<'\n';
	}
//		for(int i=1; i<=n; i++) {
//			for(int j=1; j<=n; j++) {
//				cout<<f[n][i][j]<<" ";
//			}
//			cout<<endl;
//		}

	return 0;
}
//Ren5Jie4DiLing5%
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

