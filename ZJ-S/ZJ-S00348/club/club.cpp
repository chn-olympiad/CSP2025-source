#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct g{
	int x,val;
}a[N];
struct g1{
	int c[4],p;
}b[N];
int ans,n,s[10][10],dp[N][10];
#define OPEN freopen("club.in","r",stdin),freopen("club.out","w",stdout);
bool cmp(g x,g y)
{
	return x.val > y.val;
}
bool cmp1(g1 x,g1 y)
{
	return x.p > y.p;
}
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	OPEN
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= 3;j++) cin >> b[i].c[j];
			b[i].p = max(b[i].c[1],max(b[i].c[2],b[i].c[3]));
		}
		sort(b + 1,b + n + 1,cmp1);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++) a[j].val = b[i].c[j],a[j].x = j;
			sort(a + 1,a + 3 + 1,cmp);
			if(i == 1){
				for(int j = 1;j <= 3;j++) {
					dp[i][j] = a[j].val;
					s[j][a[j].x]++;
				}
				continue;
			}
			for(int j = 1;j <= 3;j++){
				for(int k = 1;k <= 3;k++){
					if(s[j][a[k].x] < n / 2){
						s[j][a[k].x]++;
						dp[i][j] = dp[i - 1][j] + a[k].val;
						break;
					}
				}
			}
		}
		cout << max(dp[n][1],max(dp[n][2],dp[n][3])) << "\n";
		memset(s,0,sizeof(s));
	}
	return 0;
}
