#include<bits/stdc++.h>
using namespace std;
string num;
const int M = 1e6 + 10;
int n[M], p;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cin.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> num;
	int len = num.size();
	for (int i = 0; i <= len - 1; i++) {
		if (num[i] >= '0' && num[i] <= '9') n[p++] = num[i] - '0';
	}
	sort(n, n + p, cmp);
	for (int i = 0; i <= p - 1; i++) cout << n[i];
	return 0;
}
