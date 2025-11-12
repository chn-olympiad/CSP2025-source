#include <bits/stdc++.h>
using namespace std;

int n , m;
int a[110];

int main() {
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	scanf ("%d%d",&n,&m);
	for (int i = 1;i <= n * m;i++) {
		scanf ("%d",&a[i]);
	}
	int r = a[1],y = 1;
	sort (a + 1,a + n * m + 1);
	for (int i = n * m;i >= 1;i--) {
		if (a[i] == r) {
			break;
		}else {
			y++;
		}
	}
	int t1 = y / n,t2;
	if (y % n != 0) {
		t1++;
	}
	printf ("%d ",t1);
	if (t1 & 1) {
		t2 = y % n;
		if (t2 == 0) {
			t2 = n;
		}
	}else {
		t2 = n - y % n + 1;
		if (t2 > n) {
			t2 = n;
		}
	}
	printf ("%d\n",t2);
}
