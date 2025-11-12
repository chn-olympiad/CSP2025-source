//张巍骞 SN-S00224 曲江第一学校
#include<bits/stdc++.h>
using namespace std;

int n;
const int N = 1e5+10;
int dp[N];
bool cmp(int a,int b) {
	return a>b;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		cin>>n;

		vector<int>a(n+1),b(n+1),c(n+1);
		vector<int> maxx(n+1);
		int a1 = 0,b1 = 0,c1 = 0;
		bool f = false,f1 = false;
		for(int i = 1; i<= n; i++) {
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]!=0||c[i]!=0) {
				f=  true;
			}
			if(c[i]!=0) {
				f1 = true;
			}
			maxx[i] = max(a[i],max(b[i],c[i]));
			if(maxx[i]==a[i]) {
				a1++;
			} else if(maxx[i]==b[i]) {
				b1++;
			} else {
				c1++;
			}
		}
		int asd = 0;

		if(a1<=n/2&&b1<=n/2&&c1<=n/2) {
			for(int i = 1; i<= n; i++) {
				asd+=maxx[i];
			}
			cout<<asd<<"\n";
			break;
		}
		if(!f) {
			sort(a.begin(),a.end(),cmp);
			for(int i = 1; i<= n/2; i++) {
				asd+=a[i];
			}
			cout<<asd<<"\n";
			break;
		}
		if(n<=30) {
			int dp[31][16][16][16];
			dp[1][0][0][1] = c[1];
			dp[1][0][1][0] = b[1];
			dp[1][1][0][0] = a[1];
			for(int i = 2; i<= n; i++) {
				for(int j = 0; j<=i/2; j++) {
					for(int k = 0; k<= i/2; k++) {
						for(int l = i-j-k; l<= i/2; l++) {
							if(l+k+j!=i) continue;
							dp[i][j][k][l] = max(dp[i-1][j-1][k][l]+a[i],max(dp[i-1][j][k-1][l]+b[i],dp[i-1][j][k][l-1]+c[i]));
						}
					}

				}
			}
			int maxx = 0;
			for(int i = 1; i<= n/2; i++) {
				for(int j = 1; j<= n/2; j++) {
					for(int k = 1; k<=n/2; k++) {
						if(i+j+k!=n) continue;
						maxx= max(maxx,dp[n][i][j][k]);
					}
				}
			}
			cout<<maxx<<"\n";
			break;
		}
		if(f1) {
			int dp[201][101][101];
			for(int k = 1; k<= n; k++) {
				for(int i = 1; i<= n/2; i++) {
					for(int j = 1; j<= n/2; j++) {
						dp[k][i][j] = 0;
					}
				}
			}
			dp[1][1][0] = a[1];
			dp[1][0][1] = b[1];
			for(int i = 1; i<= n; i++) {
				for(int j = 1; j<=n/2; j++) {
					for(int k = 1; k<= n/2; k++) {
						dp[i][j][k] = max(dp[i-1][j-1][k]+a[i],dp[i-1][j][k-1]+b[1]);
					}
				}
			}

			for(int j = 1; j<=n/2; j++) {
				for(int k = 1; k<= n/2; k++) {
					asd=  max(asd,dp[n][j][k]);
				}
			}
			cout<<asd<<"\n";
			break;
		}

	}
	return 0;
}
