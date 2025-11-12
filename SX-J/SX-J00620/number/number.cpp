#include <bits/stdc++.h>
using namespace std;
string s;//字符串
int num[10];//0~9个数

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s; //输入
	int n = s.size(); //s的长度
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (num[i] > 0) {
			printf("%d", i);
			num[i]--;
		}
	}
	return 0;
}