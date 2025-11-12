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

const int N = 15;

int n,m;
int a[1010];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	n = read(), m = read();
	for(int i=1; i<=n*m; i++) a[i] = read();
	
	int scr = a[1];
	sort(&a[1], &a[n*m+1], greater<int>());
	
	int pos = 0;
	for(int i=1; i<=n*m; i++)
		if(a[i] == scr) {
			pos = i;
			break;
		}
		
	int x,y;
	x = (pos-1)/n + 1;
	y = pos - (x-1)*n;
	
	if(x%2 == 0) y = n-y+1;
	
	write(x), putchar(' ');
	write(y);
	
	return 0;
}
