#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;
int t,n ;
int a[N][3];
int dp[N][3];
int paixu[3];
int f[3];
int bj[N];

void found(int f[3],int k){
	for (int j=1;j<=3;j++){
		for (int i=1;i<=3;i++){
			if (f[j]==a[k-1][i]){
				bj[j]=1;
				break;
			}
		}
	}
}

int zmax(int i){
	paixu[1]=max(dp[i-1][1],dp[i-1][2]);
	paixu[1]=max(paixu[1],dp[i-1][3]);
	paixu[3]=min(dp[i-1][1],dp[i-1][2]);
	paixu[3]=min(paixu[3],dp[i-1][3]);
	for (int j=1;j<=3;j++){
		if (paixu[1]!=dp[i-1][j] && paixu[3]!=dp[i-1][j]){
			paixu[2]=dp[i-1][j];
			break;
		}
	}
//	for (int u=1;u<=3;u++){
//		cout << paixu[u] << "    " ;
//	}
	found(paixu,i);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out ","w",stdout);
	cin >> t ;
	for (int i=1;i<=t;i++){
		cin >> n ;
		for (int j=1;j<=n;j++){
			cin >> a[j][1] >> a[j][2] >> a[j][3] ;
		}
		for (int j=1;j<=3;j++){
			dp[1][j]=a[1][j];
		}
		for (int j=2;j<=n;j++){
			zmax(j);
			for (int k=1;k<=3;k++){
				if (f[k]<(n/2)){
					f[bj[paixu[k]]]++;
					dp[j][k]=paixu[k]+a[j][k];
//					cout << dp [j][k] << endl ;
				}
			}
		}
		int y=0;
		for (int p=1;p<=3;p++){
			y=max(y,dp[n][p]);
		}
		cout << y;
	}
	return 0;
}