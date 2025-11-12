#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t, n, m, a[N][5];
int x, y, z;
int dp[N][5];

int MAX(int qwer, int asdf, int zxcv) {
	return max(max(qwer, asdf), zxcv);
}

bool check(int qwer) {
	if (qwer == 1 && x <= m) {
		return 1;
	}
	if (qwer == 2 && y <= m) {
		return 1;
	}
	if (qwer == 3 && z <= m) {
		return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--) {
		int i,j,k,f;
		x=0,y=0,z=0;
		cin >> n;
		m = n / 2;
		for (i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (i > 1) {
				for (j = 1; j <= 3; j++) {
					dp[i][j] = 0;
				}
			} else {
				dp[i][1] = a[i][1];
				dp[i][2] = a[i][2];
				dp[i][3] = a[i][3];
			}
		}
		//让j为上一个人的选择，k为本人的选择
		for (i = 2; i <= n; i++) {
			for (j = 1; j <= 3; j++) {
				if(j==1){
					x++;
				}
				if(j==2){
					x=max(0,x-1),y++;
				}
				if(j==3){
					y=max(0,y-1),z++;
				}
				for(k=1;k<=3;k++){
					if(!check(k))continue;
					if(k==1){
						z=max(0,z-1),x++;
					}
					if(k==2){
						x=max(0,x-1),y++;
					}
					if(k==3){
						y=max(0,y-1),z++;
					}
					if(dp[i][k]<=a[i][k]+dp[i-1][j]&&check(k)){
						f=k;
						dp[i][k]=a[i][k]+dp[i-1][j];
					}
				}
				z--;
				if(f==1&&check(x+1))x++;
				if(f==2&&check(y+1))y++;
				if(f==3&&check(z+1))z++;
//				cout<<dp[i][1]<<' '<<dp[i][2]<<' '<<dp[i][3]<<'\n';
			}
		}
		cout<<MAX(dp[n][1],dp[n][2],dp[n][3])<<'\n';
	}
	return 0;
}
//新浪漫主义
//B

//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0