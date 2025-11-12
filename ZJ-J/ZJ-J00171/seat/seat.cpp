#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n , m , x , rk , a[110];

int main () {
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	scanf ("%d%d" , &n , &m);
	for (int i = 1;i <= n * m;i++) scanf ("%d" , &a[i]);
	x = a[1];
	sort (a + 1 , a + n * m + 1);
	reverse(a + 1 , a + n * m + 1);
	for (int i = 1;i <= n * m;i++) if (a[i] == x) rk = i;
	int sx = 1 , sy = 1 , d = 1;
	for (int i = 2;i <= rk;i++) {
		if ((sy == 1&&d == -1)||(sy == n&&d == 1)) {
			d *= -1;
			sx++;
		} else {
			sy += d;
		}
	}
	printf ("%d %d\n" , sx , sy);
	return 0;
}