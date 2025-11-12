#include <bits/stdc++.h>

#define F freopen("xor.in", "r", stdin);freopen("xor.out", "w", stdout)

using namespace std;

const int N = 5e5 + 5;

int n, k;

int a[N];
int s[N];


struct Node {
	
	int l, r;
	
	
	friend bool operator < (Node a, Node b) {
		return a.r != b.r ? a.r < b.r : a.l > b.l;
	}
}p[N];


int main (void) {
	F;
	
	cin >> n >> k;
	int maxv = 0;
	int cnt1 = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt1 += a[i];
		maxv = max(maxv, a[i]);
	}
	if(maxv == 1) {
		cout << cnt1;
		return 0;	
	}
	
	
	s[0] = 0, s[1] = a[1];
	
	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] ^ a[i];
	}
	
	int cnt = 0;
	
	for(int l = 1; l <= n; l++) {
		for(int r = l; r <= n; r++) {
			if((s[r] ^ s[l - 1]) == k) {
				p[++cnt].l = l;
				p[cnt].r = r;
				break;
			}
		}
	}
	
	sort(p + 1, p + 1 + cnt);
	
	
	int res = 1;
	int r = p[1].r;
	
	for(int i = 1; i <= cnt; i++) {
		if(r < p[i].l) {
			res++;
			r = p[i].r;
		}
	}
	
	cout << res;
	return 0;
}

