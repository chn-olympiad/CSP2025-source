#include <bits/stdc++.h>
using namespace std;
int s[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	long long s, mmax = 0;
	cin >> s;
	int l = s.size();
	for (long long  i = 0; i < l; i++) {
		if (l[i] >= '0' || l[i] <= '9')
			mmax++;
	}
}
cout << mmax;
return 0;
}