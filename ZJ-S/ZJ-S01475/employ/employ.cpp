#include <bits/stdc++.h>
#define _for(i, x, y) for(int (i)=(x); (i)<=(y); ++(i))
using namespace std;
const int maxn = 505;
const int mod = 998244353;

int n, m;
int p[maxn];
int s[maxn];
int c[maxn];
int ans=0;

void caseA() {
	
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	_for (i, 1, n) {
		p[i] = i;
	}
	
	string str;
	cin >> str;
	
	bool sIsAll1 = true;
	_for (i, 1, n) {
		s[i] = str[i-1] == '0' ? 0 : 1;
		if (!s[i]) sIsAll1=false;
	}

	_for (i, 1, n) {
		cin >> c[i];
	}
	
	if (n>12 && sIsAll1) {
		caseA();
		return 0;
	}
	
	do {
		int acc=0;
		int rej=0;
		
		_for (i, 1, n) {
			if (c[p[i]] <= rej) {
				++rej;
				continue;
			}
			
			if (s[i]) {
				++acc;
			} else {
				++rej;
			}
		}
		
		if (acc >= m) {
			++ans;
		}
	} while(next_permutation(p+1, p+1+n));

	cout << ans << "\n";
	return 0;
}
