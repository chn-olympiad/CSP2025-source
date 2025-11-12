#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
int a[N];
bool cmp(int x, int y) {
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s;
	int ls = s.size();
	int cnt  = 0;
	for (int i = 0; i < ls; i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			a[i] = s[i] - '0';
			cnt++;
		}
	}
	sort(a, a + ls, cmp);
	for (int i = 0; i < cnt; i++) cout << a[i];
	return 0;
}
