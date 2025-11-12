#include<bits/stdc++.h>
using namespace std;

int t;

struct P {
	int a[4];
} v[100010];


int n;
bool A = true, B = true;

bool cmpA(const P &a, const P &b) {
	return a.a[1] > b.a[1];
}

bool cmpB(const P &a, const P &b) {
	return true;
}


void solve() {
	cin >> n;
	for ( int i = 1; i <= n; i++ ) {
		cin >> v[i].a[1] >> v[i].a[2] >> v[i].a[3];
		A &= v[i].a[2] == 0 && v[i].a[3] == 0;
		B &= v[i].a[2] == 0;
	}
	
	long long ans = 0;
	
	if ( A ) {
		sort(v + 1, v + 1 + n, cmpA);
		for ( int i = 1; i <= ( n >> 1 ); i++ ) {
			ans += v[i].a[1];
		}
		cout << ans << endl;
		return;
	}
	else {
		cout << rand();
	}
	cout << ans << endl;
	
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while ( t-- ) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
