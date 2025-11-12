#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 500;

bool hard[MAXN + 5];
int c[MAXN + 5];

int perm[MAXN + 5]; 

int main() {
//	freopen(R"(C:\Users\Administrator\Desktop\csps\down\employ\employ3.in)", "r", stdin);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		char c;
		cin >> c;
		hard[i] = (c == '0');
	}
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for(int i = 0; i < n; i++) {
		perm[i] = i + 1;
	}
	int ans = 0;
	do {
		int accepted = 0, rejected = 0;
		for(int i = 0; i < n; i++) {
			int x = perm[i] - 1;
			if(rejected >= c[x] || hard[i]) {
				rejected++;
				continue;
			}
			accepted++;
			if(accepted >= m) {
				ans++;
				break;
			}
		}
	} while(next_permutation(perm, perm + n));
	cout << ans << endl;
}
