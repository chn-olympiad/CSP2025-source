#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		long long n, cnt = 0;
		cin >> n;
		vector<long long> a(n), b(n), c(n);
		for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		for(int i = n - 1; i >= n / 2; i--) cnt += a[i] + b[i] + c[i];
		cout << cnt << '\n';
	}
	return 0;
}

