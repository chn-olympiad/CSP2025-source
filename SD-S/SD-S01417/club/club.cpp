#include<bits/stdc++.h>
using namespace std;
int t;
const int N = 1e5 + 5;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t --)
	{
		long long n;
		cin >> n;
		bool p = 0;
		long long a[N] = {0}, b[N] = {0}, c[N] = {0};
		bool f1 = 1, f2 = 1, f3 = 1;
		for(int i = 1;i <= n;i ++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if(b[i] != 0 || c[i] != 0)f1 = 0;
			if(a[i] != 0 || c[i] != 0)f2 = 0;
			if(b[i] != 0 || a[i] != 0)f3 = 0;
		}
		if(f1 == 1 || f2 == 1 || f3 == 1)
		
		{
			sort(a + 1, a + n + 1, cmp);
	        sort(b + 1, b + n + 1, cmp);
	        sort(c + 1, c + n + 1, cmp);
		}
		
		bool flag = 0, flbg = 0, flcg = 0;
		long long num[4] = {0, 0, 0, 0};
		long long ans = 0;
		for(int i = 1;i <= n;i ++)
		{
			int mod = max(a[i], max(b[i], c[i]));
			int pl;
			if(mod == a[i])pl = 1;
			else if(mod == b[i]) pl = 2;
			else if(mod == c[i])  pl = 3;
			else
			{
			}
			if(num[1] >= n / 2)flag = 1;
			if(num[2] >= n / 2)flbg = 1;
			if(num[3] >= n / 2)flcg = 1;
			if(flag == 1 && flbg == 1 && flcg == 1)
			{
				break;
			}
			else if(flag == 1 && flbg == 1 && flcg == 0)
			{
				ans += c[i];
				num[3] ++;
			}
			else if(flag == 1 && flbg == 0 && flcg == 0)
			{
				if(b[i] > c[i])
				{
					ans += b[i];
					num[2] ++;
				}
				else
				{
					ans += c[i];
					num[3] ++;
				}
			}
			else if(flag == 1 && flbg == 0 && flcg == 1)
			{
				sort(b + i + 1, b + n + 1, cmp);
				ans += b[i];
				num[2] ++;
			}
			else if(flag == 0 && flbg == 1 && flcg == 0)
			{
				if(a[i] > c[i])
				{
					ans += a[i];
					num[1] ++;
				}
				else
				{
					ans += c[i];
					num[3] ++;
				}
			}
			else if(flag == 0 && flbg == 0 && flcg == 0)
			{
				num[pl] ++;
				ans += mod;
			}
			else if(flag == 0 && flbg == 0 && flcg == 1)
			{
				if(a[i] > b[i])
				{
					ans += a[i];
					num[1] ++;
				}
				else
				{
					ans += b[i];
					num[2] ++;
				}
			}
			else
			{
				sort(a + i + 1, a + n + 1, cmp);
				ans += a[i];
				num[1] ++;
			}
		}
		cout << ans << endl;
	}
}
