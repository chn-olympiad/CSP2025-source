#include<bits/stdc++.h>
using namespace std;

#define I inline
#define gc getchar

const int N = 100010;
int a[N][4], n, cnt[3], pos[N];
I int read() {
	int x = 0; char ch = gc();
	while(ch < '0' || ch > '9') ch = gc();
	while(ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = gc();
	return x;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while(T--) {
		n = read(); int m = n / 2, sum = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		int mxpos = 0;
		for(int i = 1; i <= n; i++) {
			int mx = -1; pos[i] = -1;
			for(int j = 0; j < 3; j++) {
				a[i][j] = read();
				if(a[i][j] > mx) pos[i] = j, mx = a[i][j];
			}
			cnt[pos[i]]++; sum += mx;
			if(cnt[pos[i]] > cnt[mxpos]) mxpos = pos[i];
		}
//		cout << mxpos << ' ' << cnt[mxpos] << '\n';
		if(cnt[mxpos] <= m) {
			cout << sum << '\n';
			continue;
		}
		else {
			vector<int> v; v.clear();
			int delta = cnt[mxpos] - m;
//			cout << "delta = " << delta << '\n';
			for(int i = 1; i <= n; i++) if(mxpos == pos[i]) {
//				cout << "i = " << i << '\n';
				if(mxpos == 0) v.push_back(a[i][0] - max(a[i][1], a[i][2]));
				if(mxpos == 1) v.push_back(a[i][1] - max(a[i][0], a[i][2]));
				if(mxpos == 2) v.push_back(a[i][2] - max(a[i][0], a[i][1]));
			}
			sort(v.begin(), v.end());
			for(int i = 0; i < delta; i++) sum -= v[i];
			cout << sum << '\n';
		}
		
	}
	return 0;
}
