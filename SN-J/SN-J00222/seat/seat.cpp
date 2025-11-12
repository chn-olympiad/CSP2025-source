//tyy tyz 8z03
#include <bits/stdc++.h>
using namespace std;
int n , m , a[105] , x , h , l;
int main ()
{
	freopen ("seat.in" , "r" , stdin);
	freopen ("seat.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i ++) cin >> a[i];
	x = a[1];
	sort (a + 1 , a + n * m + 1);
	h = l = 1;
	for (int i = n * m;i >= 1;i --)
	{
		if (a[i] == x)
		{
			cout << l << " " << h;
			return 0;
		}
		if ((l & 1) && h == n) l ++;
		else if (! (l & 1) && h == 1) l ++;
		else if (l & 1) h ++;
		else h --;
	}
	return 0;
}
