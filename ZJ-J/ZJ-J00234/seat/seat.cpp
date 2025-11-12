#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, m, a[N];
inline bool cmp(int x, int y){
	return x > y;
}
pair<int, int> ans[N];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	const int all = n * m;
	for(int i = 1; i <= all;i ++)cin >> a[i];
	int num = a[1];
	sort(a + 1, a + all + 1, cmp);
	int x = 1, y = 1;
	for(int i = 1;i <= all;i ++){
		ans[i] = {x, y};
		if(x & 1){
			if(y == n)x ++, y = n;
			else y ++;
		}
		else{
			if(y == 1)x ++, y = 1;
			else y --;
		}
	}
	for(int i = 1;i <= all;i ++)
		if(a[i] == num){
			cout << ans[i].first << ' ' << ans[i].second;
			return 0;
		}
	return 0;
}
