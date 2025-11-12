#include <bits/stdc++.h>
#define int long long
constexpr int MAXN = 100000, MAXN0=200;
using namespace std;
int n, dat[MAXN+1][3], res = 0;

int dp0[MAXN0/2][MAXN0/2][MAXN0/2];
void solution0(){
	//cout << "running";
	for(int i=1;i<=n;i++){
		for(int j=min(i,n/2);j>=0;j--){
			for(int k=min(i-j,n/2);k>=0;k--){
				for(int l=min(i-j-k,n/2);l>=0;l--){
					if(j>0)  dp0[j][k][l] = dp0[j-1][k][l]+dat[i][0];
					if(k>0)  dp0[j][k][l] = max(dp0[j][k][l], dp0[j][k-1][l]+dat[i][1]);
					if(l>0)  dp0[j][k][l] = max(dp0[j][k][l], dp0[j][k][l-1]+dat[i][2]);
					//cout << dp0[j][k][l] << endl;
					//if(dp0[j][k][l]>res)  cout << i << " " << j << " " << k << " " << l << " " << dp0[j][k][l] << endl; 
					res = max(res,dp0[j][k][l]);
					//cout << i << " " << j << " " << k << " " << l;
				}
			}
		}
		//for(int j=0;j<=2;j++)  cout << dp0[0][j][0] << " ";
		//cout << endl;
	}
}

signed main(){
	//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	for(int t0=0;t0<t;t0++){
		memset(dp0, 0, sizeof(int)*(n*n*n/8+1));
		memset(dat, 0, sizeof(int)*(n*3+3));
		res = 0;
		cin >> n;
		for(int i=1;i<=n;i++)  cin >> dat[i][0] >> dat[i][1] >> dat[i][2];
		solution0();//cout << endl;
		cout << res << endl;
	} 
	return 0;
}


