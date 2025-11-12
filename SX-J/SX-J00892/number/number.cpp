#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string Str;
	cin >> Str;
	int N = Str.length();
	vector<int> Digits(N);
	int M = 0;
	for (int i = 0; i < N ; i++) {
		if (isdigit(Str[i])) {
			Digits[i] = Str[i] - '0';
			M = M + 1;
		}
	}
	sort(Digits.begin(), Digits.end(), cmp);
	for (int i = 0; i < M; i++) {
		cout << Digits[i];
	}

	return 0;
}

