#include<bits/stdc++.h>
#define m(a) memset(a, 0, sizeof(a))
#define endl "\n"
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N][5];
int up, ans, c[N], cb1[N], cb2[N], cb3[N], cnt1, cnt2, cnt3;
bool cmp(int a, int b){
	return c[a] < c[b];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		m(cb1); m(cb2); m(cb3); cnt1 = cnt2 = cnt3 = ans = 0;
		cin >> n;
		up = n/2;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
			int maxn = max(a[i][1], max(a[i][2], a[i][3]));
			ans += maxn;
			if(maxn == a[i][1]){
				cb1[++cnt1] = i;
				c[i] = maxn - max(a[i][2], a[i][3]);
			}
			else if(maxn == a[i][2]){
				cb2[++cnt2] = i;
				c[i] = maxn - max(a[i][1], a[i][3]);
			}
			else {
				cb3[++cnt3] = i;
				c[i] = maxn - max(a[i][1], a[i][2]);
			}
		}
		if(cnt1 > up){
			sort(cb1 + 1, cb1 + cnt1 + 1, cmp);
			int now = 0;
			while(cnt1 > up){
				ans -= c[cb1[++now]];
				cnt1--;
			}
		}
		else if(cnt2 > up){
			sort(cb2 + 1, cb2 + cnt2 + 1, cmp);
			int now = 0;
			while(cnt2 > up){
				ans -= c[cb2[++now]];
				cnt2--;
			}
		}
		else if(cnt3 > up){
			sort(cb3 + 1, cb3 + cnt3 + 1, cmp);
			int now = 0;
			while(cnt3 > up){
				ans -= c[cb3[++now]];
				cnt3--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}