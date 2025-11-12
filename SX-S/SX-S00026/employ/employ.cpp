#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
template<typename T>

inline void read(T &x) {
	bool f = 1;
	x = 0;
	char ch;
	ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = !f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	x = (f ? x : -x);
	return ;
}
template<typename T>

inline void print(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
	return ;
}



int main() {

	return 0;
}