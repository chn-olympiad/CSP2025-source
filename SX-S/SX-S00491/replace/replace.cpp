#include <bits/stdc++.h>
using namespace std;
char buf[1 << 20], *p1, *p2;
// #define getchar() (p1 == p2 &&(p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)

void rd(int &a) {
	a = 0;
	char c;
	while ((c = getchar()) < 48);
	do
		a = (a << 3) + (a << 1) + (c ^ 48);
	while ((c = getchar()) > 47);
}

void wt(int &a) {
	static int st[35];
	int top = 0;
	do {
		st[++top] = a % 10;
		a /= 10;
	} while (a);
	while (top)
		putchar(st[top--] + '0');
}

int main() {
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
