#include <bits/stdc++.h>
using namespace std;
int tong[130];//存储数字的个数
char n[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	gets(n);
//	cout << n << endl;
	int i = strlen(n);
//	cout << i;
	for (int j = 0; j < i; j++) {
		if (n[j] - 48 >= 0 && n[j] - 48 <= 9) {
			tong[n[j] - 48] ++;
		}
//		tong[(int)n[j]]++;
	}
	for (int j = 9; j >= 0; j--) {
//		cout << j << "的数量：" << tong[j] << endl;
		for (int m = 1; m <= tong[j]; m++) {
			cout << j;
		}
	}
	return 0;
}