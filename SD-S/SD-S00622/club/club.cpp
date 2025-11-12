#include<bits/stdc++.h>
using namespace std;
const int N = 100007;
int t, n, x;
struct node
{
	int d1, d2, d3, c;
}a[N];
bool cmp(node x, node y)
{
	return x.c > y.c;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
		int suma, sumb, sumc;
		suma = sumb = sumc = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i].d1 >= a[i].d2 && a[i].d1 >= a[i].d3) suma++;
			else if(a[i].d2 >= a[i].d1 && a[i].d2 >= a[i].d3) sumb++;
			else if(a[i].d3 >= a[i].d1 && a[i].d3 >= a[i].d2) sumc++;
		}
		if(suma < sumb && sumc < sumb)
		{
			for(int i = 1; i <= n; i++) swap(a[i].d1, a[i].d2);
		}
		if(suma < sumc && sumb < sumc)
		{
			for(int i = 1; i <= n; i++) swap(a[i].d1, a[i].d3);
		}
		if(max(suma, max(sumb, sumc)) > n / 2)
		{
			for(int i = 1; i <= n; i++) a[i].c = min(a[i].d1 - a[i].d2, a[i].d1 - a[i].d3);
			sort(a + 1, a + n + 1, cmp);
			for(int i = 1; i <= n / 2; i++)
			{
				ans += a[i].d1;
			}
			for(int i = n / 2 + 1; i <= n; i++)
			{
				ans += max(a[i].d2, a[i].d3);
			}
		}
		else
		{
			for(int i = 1; i <= n; i++) ans += max(a[i].d1, max(a[i].d2, a[i].d3));
		}
		cout << ans << "\n";
	}
	return 0;
}
