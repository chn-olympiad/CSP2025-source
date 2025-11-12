#include <bits/stdc++.h>
using namespace std;
string a;
long long num[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a.size(); i++)
		if (a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6'
		        || a[i] == '7' || a[i] == '8' || a[i] == '9')
			num[a[i] - '0']++;
	if (num[1] == 0 && num[2] == 0 && num[3] == 0 && num[4] == 0 && num[5] == 0 && num[6] == 0 && num[7] == 0
	        && num[8] == 0 && num[9] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 9; i >= 0; i--)
		for (int j = 0; j < num[i]; j++)
			cout << i;
	return 0;
}
