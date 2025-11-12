#include <bits/stdc++.h>

#define int long long

#define all(A) A.begin(), A.end()

#define pb push_back

#define rep(A, B, C) for (int A = B; A <= C; ++A)

#define rep2(A, B, C, D) for (int A = B; A <= C; A += D)

using namespace std;

inline int read() {
	int x = 0, f = 1;

	char ch = getchar();

	while (!isdigit(ch)) {
		if (ch == '-') f = -1;

		ch = getchar();
	}

	while (isdigit(ch))
		x = x * 10 + (ch - '0'), ch = getchar();

	return x * f;
}

typedef pair<int, int> PII;

const int N = 1e6 + 5;

string s1[N], s2[N];

int n, q;

signed main() {
	freopen("replace.in", "r", stdin);

	freopen("replace.out", "w", stdout);

	n = read(), q = read();
	
	rep(i, 1, n) cin >> s1[i] >> s2[i];
	
	while (q --) {
		string t1, t2;
		
		cin >> t1 >> t2;
		
		int ans = 0;
		
		rep(i, 1, n) {
			if (t1.size() < s1[i].size()) continue;
			
			rep(j, 0, t1.size() - s1[i].size()) {
				int flag = 1;
				
				rep(k, 0, s1[i].size() - 1)
					if (s1[i][k] != t1[k + j])
						flag = 0;
						
				if (flag) {
					string t = "";
					
					if (t1.size() != s1[i].size())
						rep(k, 0, j - 1)
							t = t + t1[k];
						
					rep(k, j, s1[i].size() + j - 1)
						t =  t + s2[i][k];
					
					if (t1.size() != s1[i].size())	
						rep(k, s1[i].size() + j, t1.size() - 1)
							t = t + t1[k];
						
					if (t == t2) ans ++;
					
				}
				
				
			}
			
			
		}
		
		cout << ans << endl;
	}


	return 0;
}

