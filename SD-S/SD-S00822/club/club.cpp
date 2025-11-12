#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=205,NN=105;
int a[N][3],b[N];
int f[N][NN][NN][NN];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T,n;
	cin>>T;
	while(T--) {
		cin>>n;
		int t=n/2;
		bool ff=1;
		for(int i=1; i<=n; i++) {
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]||a[i][2])ff=0;
		}
		if(ff) {
			for(int i=1; i<=n; i++)b[i]=a[i][0];
			sort(b+1,b+1+n);
			int ans=0;
			for(int i=n; i>=n/2+1; i--)ans+=b[i];
			cout<<ans<<"\n";
			continue;
		}
		f[1][1][0][0]=a[1][0];
		f[1][0][1][0]=a[1][1];
		f[1][0][0][1]=a[1][2];
		for(int i=1; i<=n; i++) {
			for(int x=0; x<=t; x++) {
				for(int y=0; y<=t; y++) {
					for(int z=0; z<=t; z++) {
						if(x!=0)f[i][x][y][z]=max(f[i][x-1][y][z]+a[i][0],f[i][x][y][z]);
						if(y!=0)f[i][x][y][z]=max(f[i][x][y-1][z]+a[i][1],f[i][x][y][z]);
						if(y!=0)f[i][x][y][z]=max(f[i][x][y][z-1]+a[i][2],f[i][x][y][z]);
					}
				}
			}
		}
		int ans=-1;
		for(int x=0; x<=t; x++) {
			for(int y=0; y<=t; y++) {
				for(int z=0; z<=t; z++) {
					ans=max(ans,f[n][x][y][z]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
