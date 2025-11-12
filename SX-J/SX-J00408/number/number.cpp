#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
int a[1000003];
string s;

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int sum = 0;
	cin >> s;
	int n = s.size();
	if (n == 1) {
		cout << s;
		return 0;
	}
	if (n == 2) {
		fr(i, 0, 1) {
			if (s[0] <= '9' && s[0] >= '0' && s[1] <= '9' && s[1] >= '0') {
				if (s[0] < s[1])
					cout << s[1] << s[0];
				else
					cout << s[0] << s[1];
				return 0;
			}
			if (s[i] <= '9' && s[i] >= '0') {
				cout << s[i];
				return 0;
			}
		}
		return 0;
	}
	fr(i, 0, n - 1) {
		if (s[i] <= '9' && s[i] >= '1')
			a[i] = s[i];
		if (s[i] == '0')
			sum++;
	}
	sort(a + n, a, cmp);
	fr(i, 0, n - 1) {
		if (a[i] != 0)
			cout << a[i];
	}
	fr(i, 1, sum) cout << "0";
	return 0;
}//()&&s[0]>=s[1]
