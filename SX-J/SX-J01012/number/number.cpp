#include <bits/stdc++.h>;
using namespace std;
int a[1000005];

bool f(int x, int y) {
	return x > y;
}

int main() {
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s, n;
	cin >> s;
	int x = 0, sum = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			n[x] = s[i];
			x++;
		}
	}
	for (int i = 0; i < x; ++i) {
		a[i] = n[i] - '0';
	}
	sort(a, a + x + 1, f);
	for (int i = 0; i < x; ++i) {
		sum = sum * 10 + a[i];
	}
	printf("%d", sum);
	fclose(stdin);
	fclose(stdin);
	return 0;
}