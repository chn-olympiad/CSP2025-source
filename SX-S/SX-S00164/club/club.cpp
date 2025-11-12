#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5+5;
int T, n;
int m[N][3], mm[N];
int part[5], part1[5];
int cnt[5], sum;


signed main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> T;
	while (T--) {
		memset(part, INT_MAX, sizeof(part));
		memset(cnt, 0, sizeof(cnt));
		memset(mm, 0, sizeof(mm));
		sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> m[i][1] >> m[i][2] >> m[i][3];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				if (m[i][j] == 0)
					continue;
				if (cnt[j] < n / 2) {
					if (mm[i] != 0) {
						if (sum - m[i][mm[i]] + m[i][j] <= sum)
							continue;
						else {
							sum = sum - m[i][mm[i]] + m[i][j];
							cnt[j]++;
							part[j] = min(m[i][j], part[j]);
							cnt[mm[i]]--;
							part[mm[i]] = INT_MAX;
							mm[i] = j;
						}
					} else {
						sum += m[i][j];
						cnt[j]++;
						part[j] = min(m[i][j], part[j]);
						mm[i] = j;
					}

				} else {
					if (mm[i] == 0) {
						if (sum + m[i][j] - part[j] <= sum)
							continue;
						else {
							sum = sum - part[j] + m[i][j];
							part[j] = min(part[j], m[i][j]);
							mm[i] = j;
						}
					} else {
						if (sum - m[i][mm[i]] + m[i][j] - part[j] <= sum)
							continue;
						else {
							sum = sum - m[i][mm[i]] + m[i][j] - part[j];
							part[j] = m[i][j];
							//part[mm[i]] = INT_MAX;
							cnt[mm[i]]--;
							mm[i] = j;
						}
					}

				}
			}
		}
		cout << sum << endl;

	}

	return 0;
}
/*
for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(cnt[j]<n/2){
					if(mm[i]!=0){
						if(sum-m[i][mm[i]]+m[i][j]<=sum) continue;
					}
					sum+=m[i][j];
					cnt[j]++;
					part[j]=min(m[i][j],part[j]);
					mm[i]=j;
				}else{
					if(mm[i]!=0){
						if(sum-m[i][mm[i]])
					}
					if(sum-part[j]+m[i][j]>sum){
						sum=sum-part[j]+m[i][j];
						part[j]=m[i][j];
						mm[i]=j;
					}
				}
			}
		}


*/


/*

for(int i=1;i<=n;i++){
			if(m[i].index==1){
				if(dp[1]==n/2 && sum-part[1]+m[i].a1>sum){
					sum=sum-part[1]+m[i].a1;
					part[1]=m[i].a1;
				}else if(dp[1]<n/2){
					sum+=m[i].a1;
					part[1]=m[i].a1;
				}else if(dp[1]==n/2 && sum-part[1]+m[i].a1<=sum){
					if(m[i].a2>=m[i].a3) m[i].index=2;
					else m[i].index=3;
				}
			}
		}

if(m[i].a1>=m[i].a2 && m[i].a1>=m[i].a3) m[i].index=1;
			else if(m[i].a2>=m[i].a1 && m[i].a2>=m[i].a3) m[i].index=2;
			else if(m[i].a3>=m[i].a2 && m[i].a3>=m[i].a1) m[i].index=3;

*/
