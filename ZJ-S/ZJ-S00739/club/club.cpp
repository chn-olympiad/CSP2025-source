#include<bits/stdc++.h>

namespace IO {
	inline int read() {
		int ret = 0, f = 1;char ch = getchar();
		while (ch < '0' || ch > '9') {
			if (ch == '-') f = -f;
			ch = getchar();
		}
		while (ch >= '0' && ch <= '9') {
			ret = (ret << 1) + (ret << 3) + (ch ^ 48);
			ch = getchar();
		}
		return ret * f;
	}
	void write(int x) {
		if (x < 0) putchar('-'), x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
}

using namespace std;
using namespace IO;

const int maxn = 1e5 + 5;

int n, ans, T;
int a[maxn][3];

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	T = read();
	
	while (T--) {
		n = read();
		
		vector<int> v1, v2, v3;
		ans = 0;
		
		for (int i = 1; i <= n;i++) {
			a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
			int Max = max(a[i][0], a[i][1]), Maxx = min(a[i][0], a[i][1]), pos = a[i][1] > a[i][0];
			if (a[i][2] > Max) Maxx = Max, Max = a[i][2], pos = 2;
			else if (a[i][2] > Maxx) Maxx = a[i][2];
			
			int res = Max - Maxx;ans += Max;
			if (pos == 0) v1.push_back(res);
			if (pos == 1) v2.push_back(res);
			if (pos == 2) v3.push_back(res);
		}
		
//		cout << ans << "nailong\n";
		
		int len1 = v1.size(), len2 = v2.size(), len3 = v3.size(), Len = max({len1, len2, len3});
		if (Len > n / 2) {
			if (len1 >= len2 && len1 >= len3) {
				sort(v1.begin(), v1.end(), cmp);
				for (int i = 0;i < len1 - n / 2;i++) ans -= v1[i];
			}
			else if (len2 >= len1 && len2 >= len3) {
				sort(v2.begin(), v2.end(), cmp);
				for (int i = 0;i < len2 - n / 2;i++) ans -= v2[i];
			}
			else if (len3 >= len1 && len3 >= len2) {
				sort(v3.begin(), v3.end(), cmp);
				for (int i = 0;i < len3 - n / 2;i++) ans -= v3[i];
			}
		}
		
		write(ans), putchar(10);
	}
	
	return 0;
}
