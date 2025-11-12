#include<iostream>
#include<algorithm>
using namespace std;
int a[5005];
long long s = 0;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	sort(a + 1, a + 1+ n);
	
	for(int pn = 3; pn <= n; pn ++)
	{
		for(int zd = pn; zd <= n; zd++)
		{
			int l = 1, r = zd - 1;
			while(l < r)
			{
				for(int i = l; i <= r; i++)
				{
					if(a[l] + a[i] > zd)
					{
						s += 1;
						s %= 998244353;
					}
				l++;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
