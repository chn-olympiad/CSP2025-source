#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct node {
	int p1, p2, p3;
};

node a[N];

bool cmp(node x, node y) {
	int mxx = max(x.p1, max(x.p2, x.p3));
	int mnx = min(x.p1, min(x.p2, x.p3));
	int mdx = x.p1 + x.p2 + x.p3 - mxx - mnx;
	int mxy = max(y.p1, max(y.p2, y.p3));
	int mny = min(y.p1, min(y.p2, y.p3));
	int mdy = y.p1 + y.p2 + y.p3 - mxy - mny;
	return (mxx - mdx) > (mxy - mdy);
}

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i].p1 >> a[i].p2 >> a[i].p3;
		}
		sort(a+1, a+n+1, cmp);
		int n1 = 0, n2 = 0, n3 = 0, sum = 0;
		int rd = n / 2;
		for(int i = 1; i <= n; i++) {
			if(n1 + 1 <= rd && n2 + 1 <= rd && n3 + 1 <= rd) {
				if(a[i].p1 == max(a[i].p1, max(a[i].p2, a[i].p3))) {
					sum += a[i].p1;
					n1++; 
				} else if(a[i].p2 == max(a[i].p1, max(a[i].p2, a[i].p3))) {
					sum += a[i].p2;
					n2++;
				} else if(a[i].p3 == max(a[i].p1, max(a[i].p2, a[i].p3))){
					sum += a[i].p3;
					n3++;
				}
			} else {
				if(n1 == rd) {
					if(a[i].p2 > a[i].p3) sum += a[i].p2;
					else sum += a[i].p3;
				} else if(n2 == rd) {
					if(a[i].p1 > a[i].p3) sum += a[i].p1;
					else sum += a[i].p3;
				} else {
					if(a[i].p1 > a[i].p2) sum += a[i].p1;
					else sum += a[i].p2;
				}
			}
		}
		cout << sum << endl;
	}
	
	return 0;
} 
