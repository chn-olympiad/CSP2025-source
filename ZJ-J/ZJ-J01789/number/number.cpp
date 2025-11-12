#include<bits/stdc++.h>

char s[1000005];
int len;
int a[1000005], top;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::cin >> s + 1;
	len = strlen(s + 1);
	for(int i = 1; i <= len; i ++) 
		if('0' <= s[i] && s[i] <= '9') 
			a[++ top] = (s[i] - '0');
	std::sort(a + 1, a + 1 + top, cmp);
	for(int i = 1; i <= top; i ++) std::cout << a[i];
	return 0;
}
