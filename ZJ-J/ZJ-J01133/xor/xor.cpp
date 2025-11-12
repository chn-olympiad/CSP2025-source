#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
	ll res = 0, neg = 1; char ch = getchar();
	while(ch<'0' or ch>'9') { if(ch == '-') neg = -1; ch = getchar(); }
	while(ch>='0' and ch<='9') res = res*10 + ch-'0', ch = getchar();
	return res * neg;
}

void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

const int N = 5e5+10;
const int M = 2e6+10;

int n,k;
int a[N];
int prexor[N];

int val_minid[M];
int min_end[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	n = read(), k = read();
	for(int i=1; i<=n; i++) a[i] = read();
	
	for(int i=1; i<=n; i++) prexor[i] = prexor[i-1] ^ a[i];
	
	for(int i=n; i>=0; i--) {
		int tmp = prexor[i] ^ k;
		if(val_minid[tmp] != 0) min_end[i] = val_minid[tmp];
		else min_end[i] = 1e9;
		
		val_minid[prexor[i]] = i;
	}
	
	for(int i=n-2; i>=0; i--)
		min_end[i] = min(min_end[i+1], min_end[i]);
		
	int idx = 0, ans = 0;
	while(idx <= n) {
		idx = min_end[idx];
		if(idx <= n) ans++;
	}
	
	write(ans);
	
	return 0;
}
