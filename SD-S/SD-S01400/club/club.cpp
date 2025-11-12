#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5;
struct node
{
	long long xx,b,c,mx = -1,mx2 = -1;
}a[MX + 10];
long long t,n,id,id2,id3,sum;
int cmp(node x,node y)
{
	return x.mx > y.mx;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		sum = 0,id = id2 = id3 = n / 2;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].xx >> a[i].b >> a[i].c;
			a[i].mx2 = max(a[i].xx,a[i].b);
			if(a[i].mx2 > a[i].c)
			{
				a[i].mx = a[i].mx2;
				a[i].mx2 = a[i].c;
			}
			else
			{
				a[i].mx = a[i].c;
			}
		}
		if(n == 2)
		{
			sum = max(a[1].xx + a[2].c,a[1].xx + a[2].b);
			sum = max(sum,a[1].b + a[2].xx);
			sum = max(sum,a[1].b + a[2].c);
			sum = max(sum,a[1].c + a[2].xx);
			sum = max(sum,a[1].c + a[2].b);
			cout << sum << '\n';
			continue;
		}
		sort(a + 1,a + 1 + n,cmp);
		for(int i = 1;i <= n;i++)
		{
			if(a[i].mx == a[i].xx && id > 0)
			{
				id--;
				sum += a[i].mx;
				continue;
			}
			else if(a[i].mx == a[i].b && id2 > 0)
			{
				id2--;
				sum += a[i].mx;
				continue;
			}
			else if(a[i].mx == a[i].c && id3 > 0)
			{
				id3--;
				sum += a[i].mx;
				continue;
			}
			else if(a[i].mx2 == a[i].b && id2 > 0)
			{
				id2--;
				sum += a[i].mx2;
				continue;
			}
			else if(a[i].mx2 == a[i].xx && id > 0)
			{
				id--;
				sum += a[i].mx2;
				continue;
			}
			else if(a[i].mx2 == a[i].b && id2 > 0)
			{
				id2--;
				sum += a[i].mx2;
				continue;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
