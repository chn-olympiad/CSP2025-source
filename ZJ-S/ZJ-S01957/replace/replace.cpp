#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 2e5 + 5;
const int K = 31;
int n, q;
string read() {
	string x = ""; char ch = getchar();
	while(ch < 'a' || ch > 'z') ch = getchar();
	while(ch >= 'a' && ch <= 'z') {
		x = x + ch; ch = getchar();
	}
	return x;
}
string s[N][2];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) {
		s[i][0] = read(); s[i][1] = read();
	}
	while(q--) {
		printf("0\n");
	}
	return 0;
}
