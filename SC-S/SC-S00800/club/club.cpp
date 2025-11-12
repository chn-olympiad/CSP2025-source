#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void f(int n, int k, int &max, int A, int B, int C, vector<vector<int>> &members, vector<int> &a, map<vector<int>, bool> &st);

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int max = 0;
		int n;
		cin >> n;
		vector<vector<int>> members(n + 1, vector<int>(4));
		vector<int> a(n + 1);
		map<vector<int>, bool> st;
		int A, B, C;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j) {
				cin >> members[i][j];
			}
		}
		
		f(n, 0, max, A, B, C, members, a, st);
		
		cout << max << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void f(int n, int k, int &max, int A, int B, int C, 
	   vector<vector<int>> &members, vector<int> &a, map<vector<int>, bool> &st) {
	if (k == n + 1) {
//		if (st.count(a) == 0) {
//			st[a] = true;
			int t = 0;
			for (int i = 1; i <= n; ++i) {
				t += members[i][a[i]];
			}
			if (t > max) {
				max = t;
			}
//		}
		
		return;
	}
	a[k] = 1;
	if (A + 1 <= n / 2) {
		f(n, k + 1, max, A + 1, B, C, members, a, st);
	}
	a[k] = 2;
	if (B + 1 <= n / 2) {
		f(n, k + 1, max, A, B + 1, C, members, a, st);
	}
	a[k] = 3;
	if (C + 1 <= n / 2) {
		f(n, k + 1, max, A, B, C + 1, members, a, st);
	}
	return;
}