#include <bits/stdc++.h>
using namespace std;
long long a[15];
string s;

int main() {
	//¼ì²é×¢ÊÍ
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long sl = s.size();
	for (int i = 0; i <= sl - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[s[i] - '0']++;
			//printf("%d++\n", s[i] - '0');
		}

	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			printf("%d", i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}