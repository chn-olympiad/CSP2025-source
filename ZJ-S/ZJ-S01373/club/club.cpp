#include <bits/stdc++.h>
using namespace std;
const int maxn=205;
int f[2][maxn/2][maxn/2][maxn/2];
int n;
int t,ans;
int a[maxn][5];
int main() 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		ans=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int p=1,i=1; i<=n; i++,p^=1) {
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++) {
					int o=(i-j-k);
					if(o<=n/2) {
						if((!j)&&k&&o)f[p][j][k][o]=max(f[p^1][j][k-1][o]+a[i][2],
							                                f[p^1][j][k][o-1]+a[i][3]);

						else if(j&&(!k)&&o)f[p][j][k][o]=max(f[p^1][j-1][k][o]+a[i][1],
							                                     f[p^1][j][k][o-1]+a[i][3]);

						else if(j&&k&&(!o))f[p][j][k][o]=max(f[p^1][j-1][k][o]+a[i][1],
							                                     f[p^1][j][k-1][o]+a[i][2]);

						else if(j&&(!k)&&(!o))f[p][j][k][o]=f[p^1][j-1][k][o]+a[i][1];
						else if((!j)&&k&&(!o))f[p][j][k][o]=f[p^1][j][k-1][o]+a[i][2];
						else if((!j)&&(!k)&&o)f[p][j][k][o]=f[p^1][j][k][o-1]+a[i][3];

						else if(j&&k&&o)f[p][j][k][o]=max(f[p^1][j-1][k][o]+a[i][1],
							                                  max(f[p^1][j][k-1][o]+a[i][2],
							                                      f[p^1][j][k][o-1]+a[i][3]));
					}
					else continue;
					if(i==n)ans=max(ans,f[p][j][k][o]);
				}
			}  
		}
				
	}
	return 0;
}