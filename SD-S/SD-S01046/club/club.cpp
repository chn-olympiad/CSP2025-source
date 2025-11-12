#include<bits/stdc++.h>
using namespace std ;
const int MX = 1e5 ;
int main()
{
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	ios::sync_with_stdio(0);
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while (t--)
	{
		int n,a[MX + 10],b[MX + 10],c[MX + 10],q[MX + 10],ans = 0,i ;
		cin >> n ;
		for (i = 1 ; i <= n ; i++)
		{
			cin >> a[i] >> b[i] >> c[i] ;
		}
		if (n == 2)
		{
			q[1] = a[1] + max(b[2],c[2]) ;
			q[2] = b[1] + max(a[2],c[2]) ;
			q[3] = c[1] + max(a[2],b[2]) ;
			ans = max(q[1],max(q[2],q[3])) ;
		}
		if (n == 4)
		{
			q[1] = a[1] + a[2] + max(b[3] + c[4],b[4] + c[3]) ;
			q[2] = a[1] + a[3] + max(b[2] + c[4],b[4] + c[2]) ;
			q[3] = a[1] + a[4] + max(b[3] + c[2],b[2] + c[3]) ;
			q[4] = a[3] + a[2] + max(b[1] + c[4],b[4] + c[1]) ;
			q[5] = a[4] + a[2] + max(b[3] + c[1],b[1] + c[3]) ;
			q[6] = a[3] + a[4] + max(b[1] + c[2],b[2] + c[1]) ;
			q[7] = b[1] + b[2] + max(a[3] + c[4],a[4] + c[3]) ;
			q[8] = b[1] + b[3] + max(a[2] + c[4],a[4] + c[2]) ;
			q[9] = b[1] + b[4] + max(a[3] + c[2],a[2] + c[3]) ;
			q[10] = b[3] + b[2] + max(a[1] + c[4],a[4] + c[1]) ;
			q[11] = b[4] + b[2] + max(a[3] + c[1],a[1] + c[3]) ;
			q[12] = b[3] + b[4] + max(a[1] + c[2],a[2] + c[1]) ;
			q[13] = c[1] + c[2] + max(b[3] + a[4],b[4] + a[3]) ;
			q[14] = c[1] + c[3] + max(b[2] + a[4],b[4] + a[2]) ;
			q[15] = c[1] + c[4] + max(b[3] + a[2],b[2] + a[3]) ;
			q[16] = c[3] + c[2] + max(b[1] + a[4],b[4] + a[1]) ;
			q[17] = c[4] + c[2] + max(b[3] + a[1],b[1] + a[3]) ;
			q[18] = c[3] + c[4] + max(b[1] + a[2],b[2] + a[1]) ;
			q[19] = a[1] + a[1] + max(c[2] + c[2],b[2] + b[2]) ;
			q[20] = b[1] + b[2] + c[1] + c[2] ;
			sort(q + 1,q + 20 + 1,greater<int>()) ;
			ans = q[1] ;
		}
		if (n == 10)
		{
			sort(a + 1,a + n + 1,greater<int>()) ;
			q[1] = a[1] + a[2] + a[3] + a[4] + a[5] + max(max(b[1] + b[2] + b[3] + b[4] + b[5],b[6] + b[7] + b[8] + b[9] + b[10]),max(c[1] + c[2] + c[3] + c[4] + c[5],c[6] + c[7] + c[8] + c[9] + c[10]));
			q[2] = a[1] + a[2] + a[3] + a[4] + max(b[5] + b[6] + b[7] + c[8] + c[9] +c[10],c[5] + c[6] + c[7] + b[8] + b[9] + b[10]) ;
			q[3] = a[1] + a[2] + a[3] + b[5] + b[6] + b[7] + b[8] + c[9] + c[10] ;
			ans = max(q[1],max(q[2],q[3])) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

