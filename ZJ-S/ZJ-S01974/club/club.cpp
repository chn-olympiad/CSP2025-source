#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=2e2+4;
const int M=1e2+2;
int w[N][3];
int f[N][M][M][M];
void solve(){
	for (int i=2; i<=n; i++){
		for (int a=0; a<=n/2; a++){
			for (int b=0; b<=n/2; b++){
				for (int c=0; c<=n/2; c++){
					f[i][a][b][c]=0;
				}
			}
		}
	}
	f[1][1][0][0]=w[1][0];
	f[1][0][1][0]=w[1][1];
	f[1][0][0][1]=w[1][2];
	for (int i=2; i<=n; i++){
		for (int a=0; a<=n/2; a++){
			for (int b=0; b<=n/2; b++){
				for (int c=0; c<=n/2; c++){
					if (a>=1){
						f[i][a][b][c]=max(f[i][a][b][c],f[i-1][a-1][b][c]+w[i][0]);
					}
					if (b>=1){
						f[i][a][b][c]=max(f[i][a][b][c],f[i-1][a][b-1][c]+w[i][1]);
					}
					if (c>=1){
						f[i][a][b][c]=max(f[i][a][b][c],f[i-1][a][b][c-1]+w[i][2]);
					}
				}
			}
		}
	}
	int ans=0;
	for (int a=0; a<=n/2; a++){
		for (int b=0; b<=n/2; b++){
			ans=max(ans,f[n][a][b][n-a-b]);
		}
	}
	cout<<ans<<"\n";
}
void solve1(){
	int ans=0;
	vector<int> tmp;
	for (int i=1; i<=n; i++){
		tmp.push_back(w[i][0]);
	}
	sort(tmp.begin(),tmp.end());
	for (int i=n/2; i<n; i++){
		ans+=tmp[i];
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		bool fl1=1;
		cin>>n;
		for (int i=1; i<=n; i++){
			for (int j=0; j<=2; j++){
				cin>>w[i][j];
			}
			if (w[i][2]!=0 || w[i][1]!=0){
				fl1=0;
			}
		}
		if (fl1){
			solve1();
		}else{
			solve();
		}
	}
	return 0;
}