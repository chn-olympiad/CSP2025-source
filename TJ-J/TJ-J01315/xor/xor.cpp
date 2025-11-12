#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e+5 + 5;
int lst[1 << 20];

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
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n = read(), k = read(), lat = 0;
	int now = 0, answer = 0;
	for(int i = 0; i < 1 << 20; i++) lst[i] = -1;
	lst[0] = 0;
	for(int i = 1; i <= n; i++) {
		now ^= read();
		if(lat <= lst[now ^ k]) answer++, lat = i;//, cout << lst[now ^ k] << ' ' << i << endl;
		lst[now] = i;
	}
	cout << answer;

    return 0;
}
