#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5+1;
struct stdu{
	int a, b, c;
}a[MX];
int dp[MX][3];
bool cmp(stdu x, stdu y){return x.a > y.a;}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int zdsg = 1; zdsg <= t; zdsg++){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b >> a[i].c;
		sort(a + 1, a + n + 1, cmp);
		int sum = 0;
		for (int i = 1; i <= n / 2; i++) sum += a[i].a;
		cout << sum << endl;
	}
	return 0;
} 
