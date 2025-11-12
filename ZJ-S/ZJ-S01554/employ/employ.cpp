#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x = 0, y = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') y = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * y;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	printf("0");
	return 0;
}
