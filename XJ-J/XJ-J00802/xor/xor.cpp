#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; 

int n, k;
int a[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
	}
	
	set<int> s;
	int res = 0;
	int ans = 0;
	for ( int i = 1; i <= n; i++ ) {
		res ^= a[i];
		if ( res == k || s.count(res ^ k) ) {
			s.clear();
			ans++;
			res = 0;
		}
		else s.insert(res);
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
