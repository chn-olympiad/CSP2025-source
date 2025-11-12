#include<bits/stdc++.h>
using namespace std;
int T , n;
int d[4] , ans = 0 ,num1 = 0;
struct point
{
	int p1 , p2 , p3 ; 
}a[100001];
struct point1
{
	int q1 , q2 , q3;
}r[100001];
int max(int x , int y)
{
	if(x >= y) return x;
	else return y;
}
void compare(int x , int y , int z)
{
	int mx = max(x , max(y , z));
	ans += mx;
	if(mx == x) d[1] ++;
	else if(mx == y) d[2] ++;
	else d[3] ++;
}
bool flag(int x)
{
	bool f = 0;
	for(int i = 1 ; i <= 4 ; i ++)
		if(d[i] > x/2) f = 1;
	if(f == 1) return 0;
	return 1;
}
int abs(int x ,int y)
{
	if(x >= y) return x - y;
	else return y-x;	
}
int bfs()
{
		if(d[1] > n/2)
		{
			for(int i = 1 ;i <= n ; i ++)
			{
				if(r[i].q1 <= r[i].q3)
				{
					int b[10001];
					b[i] = a[i].p1 - a[i].p2;
					if(b[i-1] < b[i])
						a[i-1].p1 = a[i-1].p2;
				}
				if(r[i].q3 < r[i].q1)
				{
					int b[10001];
					b[i] = a[i].p1 - a[i].p3;
					if(b[i-1] < b[i])
						a[i-1].p1 = a[i-1].p3;
				}
			}
			int num = 0;
			for(int i = 1; i <= n ; i ++)
				num += max(a[i].p1 , max(a[i].p2 , a[i].p3));
			return num;
		}
		if(d[2] > n/2)
		{
			for(int i = 1 ;i <= n ; i ++)
			{
				if(r[i].q1 <= r[i].q2)
				{
					int b[10001];
					b[i] = a[i].p2 - a[i].p1;
					if(b[i-1] < b[i])
						a[i-1].p2 = a[i-1].p1;
				}
				if(r[i].q2 < r[i].q1)
				{
					int b[10001];
					b[i] = a[i].p2 - a[i].p3;
					if(b[i-1] < b[i])
						a[i-1].p2 = a[i-1].p3;
				}
			}
			int num = 0;
			for(int i = 1; i <= n ; i ++)
				num += max(a[i].p1 , max(a[i].p2 , a[i].p3));
			return num;
		}
		if(d[3] > n/2)
		{
			for(int i = 1 ;i <= n ; i ++)
			{
				if(r[i].q2 <= r[i].q3)
				{
					int b[10001];
					b[i] = a[i].p3 - a[i].p2;
					if(b[i-1] <= b[i])
						a[i-1].p3 = a[i-1].p2;
				}
				if(r[i].q3 < r[i].q2)
				{
					int b[10001];
					b[i] = a[i].p3 - a[i].p1;
					if(b[i-1] <= b[i])
						a[i-1].p3 = a[i-1].p1;
				}
			}
			int num = 0;
			for(int i = 1; i <= n ; i ++)
				num += max(a[i].p1 , max(a[i].p2 , a[i].p3));
			return num;
		}
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> T;
	while(T --)
	{
		for(int i = 1 ; i <= 4 ; i ++) d[i] = 0;
		cin >> n;
		for(int i = 1 ;i <= n ; i ++)
		{
			cin >> a[i].p1 >> a[i].p2 >> a[i].p3;
			r[i].q1 = abs(a[i].p1 - a[i].p2);
			r[i].q2 = abs(a[i].p2 - a[i].p3);
			r[i].q3 = abs(a[i].p1 - a[i].p3);
			compare(a[i].p1 , a[i].p2 , a[i].p3);
		}
		if(d[1] <= n/2 && d[2] <= n/2 && d[3] <= n/2) 
			cout << ans << endl;
		cout << bfs() << endl;
	}
	return 0;
}
