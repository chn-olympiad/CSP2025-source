#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000010];

int main() {

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ll n = 0;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			
			s[i] -= '0';
			a[n] = s[i];
			n++;
		}

	}
	sort(a, a + n);
	for (ll i = n-1; i >=0; i--) {
		cout << a[i];
	}

	return 0;
}
