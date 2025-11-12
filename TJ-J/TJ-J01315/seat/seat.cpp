#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 105;
int a[maxn];

inline ll read() {
    ll ref = 0;
    bool f = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-')
            f = 0;
        ch = getchar();
    }
    while(isdigit(ch))
		ref = (ref << 1) + (ref << 3) + (ch ^ 48), ch = getchar();
	return (f ? ref : -ref); 
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n = read(), m = read(), N = n * m;
	for(int i = 1; i <= N; i++) a[i] = read();
	int i = 1;
	while(i < N) {
		while(i < N && a[i] < a[i + 1]) swap(a[i + 1], a[N--]);
		if(i < N) swap(a[i], a[i + 1]), i++;
	}
	i = n * m - i + 1;
	cout << ((i + n - 1) / n) << ' ' << (((i + n - 1) / n & 1) ? (i - 1) % n + 1 : n - ((i - 1) % n));

    return 0;
}
