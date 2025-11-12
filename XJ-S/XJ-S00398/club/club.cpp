#include<bits/stdc++.h>
using namespace std;
int ans,a[100001];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,x,y,z;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> n;
		ans = 0;
		for(int j = 1; j <= n; j++) {
			int cnt = -5;
			cin >> x >> y >> z;
			cnt = max(x,y);
			cnt = max(cnt,z);
			ans += cnt;
		}
		a[i] = ans;
	}
	for(int i = 1; i <= t; i++) {
		cout << a[i];
	}
	return 0;
}
