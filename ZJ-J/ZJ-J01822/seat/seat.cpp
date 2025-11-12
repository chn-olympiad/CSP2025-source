#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define upl(i, s, t, d) for(int i = (s); i <= (t); i += d)
#define dol(i, s, t, d) for(int i = (s); i >= (t); i -= d)
//#define int long long
void INIT() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
}

const int MAX = 10 + 5;
int a[MAX * MAX];

signed main() {
	INIT();
	
	int n, m;
	cin >> n >> m;
	upl(i, 1, n * m, 1)
		cin >> a[i];
	int me = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	int id = 0; // 当前第几个学生 
	bool ud = 1; // 向上 0，向下 1 
	upl(i, 1, m, 1) { // 列 
		if(ud) {
			upl(j, 1, n, 1) { // 行 
				if(a[++id] == me) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			dol(j, n, 1, 1) { // 行 
				if(a[++id] == me) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
		ud = !ud;
	}
	return 0;
}

