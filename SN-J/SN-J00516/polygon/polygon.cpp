#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read() { //¿ì¶Á
	ll ans = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		ans = (ans << 3) + (ans << 1) + ch - '0';
		ch = getchar();
	}
	return f * ans;
}

int main(){
	freopen("polygon1.in", "r", stdin);
	freopen("polygon1.out", "w", stdout);
	int n, m, c = 1, r = 1, a[10010], num = 0, a1;
	n = read();m = read();
	for (int i = 1; i <= n * m; i++){
		num++;
		a[i] = read(); 
		if (i == 1) a1 = a[i];
	}
	sort(a, a + num);
	for (int i = n, j = 0; i > 0; i--){
		j++;
		if ((j / n) % 2 == 0) c++;
		else r++;
		if (a1 == a[i]) cout << r << " " << c;
		}
	}

