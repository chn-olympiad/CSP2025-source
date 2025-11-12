#include <bits/stdc++.h>

using namespace std;

inline int rd() {
	int x = 0, w = 1;
	char ch = 0;
	while (ch < '0' || ch > '9') {
		if (ch == '-')	
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar(); 
	}
	return x * w;
}

using ull = unsigned long long;

ull P = 23331;

int n, q;

namespace sub1 {
	ull has1[2005][5], has2[5][2005], mip[2005];
	
	int lenn[2005];
	
	ull get(int id, int l, int r) {
		if (l > r)
			return 0;
		return has2[id][r] - has2[id][l - 1] * mip[r - l + 1];
	}
	
	char s1[2005], s2[2005];
	
	void sol() {
		mip[0] = 1;
		for (int i = 1; i <= 2000; ++i)	
			mip[i] = mip[i - 1] * P;
		for (int i = 1; i <= n; ++i) {
			scanf("%s%s", s1 + 1, s2 + 1);
			has1[i][1] = has1[i][2] = 0;
			int len = strlen(s1 + 1);
			for (int j = 1; j <= len; ++j)
				has1[i][1] = has1[i][1] * P + (s1[j] - 'a' + 1);
			for (int j = 1; j <= len; ++j)
				has1[i][2] = has1[i][2] * P + (s2[j] - 'a' + 1);
//			cout << has1[i][1] << " " << has1[i][2] << endl;
			lenn[i] = len;
		}
		while (q--) {
			scanf("%s%s", s1 + 1, s2 + 1);
			int len1 = strlen(s1 + 1);
			has2[1][0] = 0;
			has2[2][0] = 0;
			for (int i = 1; i <= len1; ++i)
				has2[1][i] = has2[1][i - 1] * P + (s1[i] - 'a' + 1);
			int len2 = strlen(s2 + 1);
			for (int i = 1; i <= len2; ++i)
				has2[2][i] = has2[2][i - 1] * P + (s2[i] - 'a' + 1);
//			cout<<has2[1][len1] << " " << has2[2][len2]<<endl;
			int ans = 0;
			if (len1 != len2) {
				puts("0");
				continue;
			}
			for (int i = 1; i <= len1; ++i) {
//				cout<<i<<endl;
//				cout<<get(1,1,i)<<" "<<get(2,1,i)<<endl;
				if (get(1, 1, i - 1) != get(2, 1, i - 1))
					continue;
				for (int j = 1; j <= n; ++j) {
					int r = i + lenn[j] - 1;
					if (r > len1)
						continue;
//					cout<<r<<" "<<get(1,i,r)<< ' ' << get(2, i, r) << endl;
					if (get(1, i, r) == has1[j][1] && get(2, i, r) == has1[j][2] && get(1, r + 1, len1) == get(2, r + 1, len1))
						++ans;
				}
			}
			printf("%d\n", ans);
		}
		return;
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = rd(), q = rd();
	if (n <= 1000)
		sub1 :: sol();
	return 0;
}

