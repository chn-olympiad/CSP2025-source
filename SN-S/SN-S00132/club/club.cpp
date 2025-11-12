//tyy tyz 8z03
#include <bits/stdc++.h>
using namespace std;
int T , n , wz[100005] , ans , a , b , c;
struct node
{
	int x , y , z;
}al[100005];
priority_queue <pair <int , int> > p1;
priority_queue <pair <int , pair <int , int> > > p3 , p2;
int main ()
{
	freopen ("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> T;
	while (T --)
	{
		ans = 0;
		a = 0;
		b = 0;
		c = 0;
		cin >> n;
		for (int i = 1;i <= n;i ++) cin >> al[i].x >> al[i].y >> al[i].z , wz[i] = 1;
		a = n;
		for (int i = 1;i <= n;i ++)
			if (al[i].y > al[i].x)
			{
				wz[i] = 2;
				a --;
				b ++;
				if (al[i].z > al[i].y)
				{
					wz[i] = 3;
					b --;
					c ++;
					p2.push ({al[i].y - al[i].z , {i , 2}});
				}
				else p1.push ({al[i].x - al[i].y , i});
			}
			else if (al[i].z > al[i].x)
			{
				wz[i] = 3;
				a --;
				c ++;
				p2.push ({al[i].x - al[i].z , {i , 1}});
			}
		while (c > n / 2)
		{
			int i = p2.top ().second.first , l = p2.top ().second.second;
			p2.pop ();
			if (l == 2)
			{
				wz[i] = 2;
				c --;
				b ++;
				p1.push ({al[i].x - al[i].y , i});
			}
			else
			{
				wz[i] = 1;
				c --;
				a ++;
			}
		}
		while (b > n / 2)
		{
			int i = p1.top ().second;
			p1.pop ();
			wz[i] = 1;
			b --;
			a ++;
		}
		for (int i = 1;i <= n;i ++)
			if (wz[i] == 1)
			{
				if (al[i].y - al[i].x > al[i].z - al[i].x) p3.push ({al[i].y - al[i].x , {i , 2}});
				else p3.push ({al[i].z - al[i].x , {i , 3}});
			}
		while (a > n / 2)
		{
			int i = p3.top ().second.first , l = p3.top ().second.second;
			p3.pop ();
			wz[i] = l;
			a --;
		}
		while (! p1.empty ()) p1.pop ();
		while (! p2.empty ()) p2.pop ();
		while (! p3.empty ()) p3.pop ();
		for (int i = 1;i <= n;i ++)
			if (wz[i] == 1) ans += al[i].x;
			else if (wz[i] == 2) ans += al[i].y;
			else ans += al[i].z;
		cout << ans << "\n";
	}
	return 0;
}
