#include <bits/stdc++.h>
using namespace std;

long long n, t;
struct node
{
	long long x, y, z;
}a[100005];

bool cmp1(node a, node b)
{
	if (a.x != b.x) return a.x > b.x;
	else if (a.z != b.z) return a.z > b.z;
	else return a.y > b.y;
}

bool cmp2(node a, node b)
{
	if (a.x != b.x) return a.x > b.x;
	else if (a.y != b.y) return a.y > b.y;
	else return a.z > b.z;
}

bool cmp3(node a, node b)
{
	if (a.y != b.y) return a.y > b.y;
	else if (a.z != b.z) return a.z > b.z;
	else return a.x > b.x;
}

bool cmp4(node a, node b)
{
	if (a.y != b.y) return a.y > b.y;
	else if (a.x != b.x) return a.x > b.x;
	else return a.z > b.z;
}

bool cmp5(node a, node b)
{
	if (a.z != b.z) return a.z > b.z;
	else if (a.x != b.x) return a.x > b.x;
	else return a.y > b.y;
}

bool cmp6(node a, node b)
{
	if (a.z != b.z) return a.z > b.z;
	else if (a.y != b.y) return a.y > b.y;
	else return a.x > b.x;
}
bool cmp7(node a, node b)
{
	return  a.x + a.y + a.z > b.x + b.y + b.z;
}

long long solve(long long tim)
{
	if (tim == 1) sort(a + 1, a + n + 1, cmp1);
	if (tim == 2) sort(a + 1, a + n + 1, cmp2);
	if (tim == 3) sort(a + 1, a + n + 1, cmp3);
	if (tim == 4) sort(a + 1, a + n + 1, cmp4);
	if (tim == 5) sort(a + 1, a + n + 1, cmp5);
	if (tim == 6) sort(a + 1, a + n + 1, cmp6);
	if (tim == 7) sort(a + 1, a + n + 1, cmp7);
	long long x = 0, y = 0, z = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		long long xx = a[i].x, yy = a[i].y, zz = a[i].z;
//		cin >> xx >> yy >> zz;
		if (max({xx, yy, zz}) == xx && x < n / 2) ans += xx, x++;
		else if (max({xx, yy, zz}) == yy && y < n / 2) ans += yy, y++;
		else if (max({xx, yy, zz}) == zz && z < n / 2) ans += zz, z++;
		else
		{
			if (x == n / 2) 
			{
				if (max(zz, yy) == yy && y <= n / 2) ans += yy, y++;
				else if (max(zz, yy) == zz && z <= n / 2) ans += zz, z++;
				else if (yy == n / 2) ans += zz, z++;
				else if (zz == n / 2) ans += yy, y++;
			} else if (y == n / 2) 
			{
				if (max(zz, xx) == xx && x <= n / 2) ans += xx, x++;
				else if (max(zz, xx) == zz && z <= n / 2) ans += zz, z++;
				else if (xx == n / 2) ans += zz, z++;
				else if (zz == n / 2) ans += xx, x++;
			} else if (z == n / 2) 
			{
				if (max(xx, yy) == yy && y <= n / 2) ans += yy, y++;
				else if (max(xx, yy) == xx && x <= n / 2) ans += xx, x++;
				else if (yy == n / 2) ans += xx, x++;
				else if (xx == n / 2) ans += yy, y++;
			}	
		} 
	}
	
	x = 0, y = 0, z = 0;
	long long ans2 = 0;
	for (int i = n; i >= 1; i--)
	{
		long long xx = a[i].x, yy = a[i].y, zz = a[i].z;
//		cin >> xx >> yy >> zz;
		if (max({xx, yy, zz}) == xx && x < n / 2) ans2 += xx, x++;
		else if (max({xx, yy, zz}) == yy && y < n / 2) ans2 += yy, y++;
		else if (max({xx, yy, zz}) == zz && z < n / 2) ans2 += zz, z++;
		else
		{
			if (x == n / 2) 
			{
				if (max(zz, yy) == yy && y <= n / 2) ans2 += yy, y++;
				else if (max(zz, yy) == zz && z <= n / 2) ans2 += zz, z++;
				else if (yy == n / 2) ans2 += zz, z++;
				else if (zz == n / 2) ans2 += yy, y++;
			} else if (y == n / 2) 
			{
				if (max(zz, xx) == xx && x <= n / 2) ans2 += xx, x++;
				else if (max(zz, xx) == zz && z <= n / 2) ans2 += zz, z++;
				else if (xx == n / 2) ans2 += zz, z++;
				else if (zz == n / 2) ans2 += xx, x++;
			} else if (z == n / 2) 
			{
				if (max(xx, yy) == yy && y <= n / 2) ans2 += yy, y++;
				else if (max(xx, yy) == xx && x <= n / 2) ans2 += xx, x++;
				else if (yy == n / 2) ans2 += xx, x++;
				else if (xx == n / 2) ans2 += yy, y++;
			}	
		} 
	}
	return max(ans, ans2);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
		cout << max({solve(1), solve(2), solve(3), solve(4), solve(5), solve(6), solve(7)}) << endl;	
	}
	return 0;
}
