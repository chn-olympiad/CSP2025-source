#include <bits/stdc++.h>
using namespace std;
string s;
long long number[1000000];
long long sum;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i <= len - 1; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			sum++;
			number[sum] = s[i] - '0';
		}
	}
	sort(number + 1, number + 1 + sum);
	for (int i = sum ; i > 0; i--)
		cout << number[i];
	return 0;
}