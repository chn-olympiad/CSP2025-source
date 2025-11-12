#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0,  f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
	    if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, m, k, cnt;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cnt = 1;
	n = read(); m = read(); k = read();
	for(int i = 2; i <= n * m; ++i) {
		int x = read();
		if(x > k) {
			++cnt;
		}
	}
	int now1 = 1, now2 = 1;
	while(true) {
		if(cnt == 1) {
			break;
		}
		if(now1 & 1) {
			if(now2 < n) {
				++now2;
			}
			else {
				now2 = n;
				now1++;
			}
		}
		else {
			if(now2 > 1) {
				--now2;
			}
			else {
				now2 = 1;
				now1++;
			}
		}
		--cnt;
	}
	printf("%d %d", now1, now2);
	return 0;
}
