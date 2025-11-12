#include <bits/stdc++.h>
using namespace std;

const int MOD_NUM = 998244353;
int loopnum = 3;
int anscnt = 0;

bool cmp(int a, int b) {
	return a > b;
}

int i[5001], a[5001];

void doloop(int index, int front, int last, int cnt) {
	for (i[index] = front; i[index] <= last; i[index]++) {
		if (index == loopnum) {
			if ((cnt + a[i[index]]) > (a[i[index]] * 2)) anscnt++;
				anscnt %= MOD_NUM;
		} else {
			doloop(index + 1, i[index] + 1, last + 1, cnt + a[i[index]]);
		}
	}
	//ÔÓÓãÊ±¼ä¸´ÔÓ¶È 
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);
	
	
	for (loopnum = 3; loopnum <= n; loopnum++) {
		doloop(1, 0, n - loopnum, 0);
	}
	
	cout << anscnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
