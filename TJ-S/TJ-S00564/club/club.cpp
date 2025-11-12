#include <bits/stdc++.h>
using namespace std;

long long t, n, ansp[1000],ple,ansl = 0,ans[2];

struct lik
{
	int l1 = 0;
	int l2 = 0;
	int l3 = 0;
	bool life = 1;
	bool life2 = 1;
} ;
bool cmp1(lik a1,lik a2)
{
	return a1.l1 > a2.l1;
}
bool cmp3(lik a1,lik a2)
{
	return a1.l2 > a2.l2;
}
bool cmp2(lik a1,lik a2)
{
	return a1.l3 > a2.l3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans[0] = ans[1] = 0;
		lik a[n];
		for(int i = 0; i< n;i++)
		{
			cin >> a[i].l1 >> a[i].l2 >> a[i].l3;
		}
		sort(a,a+n,cmp1);
		ple = 0;
		for(int i = 0; i< n;i++)
		{
			if(ple >= n/2)
			{
				break;
			}
			if(a[i].life)
			{
				if(a[i].l1 > a[i].l2 && a[i].l1 > a[i].l3)
				{
					ans[0] += a[i].l1;
					a[i].life = 0;
					ple++;
				}
			}
		}
		sort(a,a+n,cmp2);
		ple = 0;
		for(int i = 0; i< n;i++)
		{
			if(ple >= n/2)
			{
				break;
			}
			if(a[i].life)
			{
				if(a[i].l2 > a[i].l3)
				{
					ans[0] += a[i].l2;
					a[i].life = 0;
					ple++;
				}
			}
		}
		sort(a,a+n,cmp3);
		ple = 0;
		for(int i = 0; i< n;i++)
		{
			if(ple >= n/2)
			{
				break;
			}
			if(a[i].life)
			{
				ans[0] += a[i].l3;
				a[i].life = 0;
				ple++;
			}
		}
		ple = 0;
		for(int i = 0; i< n;i++)
		{
			if(ple >= n/2)
			{
				break;
			}
			if(a[i].life2)
			{
				if(a[i].l3 > a[i].l2 && a[i].l3 > a[i].l1)
				{
					ans[1] += a[i].l3;
					a[i].life2 = 0;
					ple++;
				}
			}
		}
		sort(a,a+n,cmp2);
		ple = 0;
		for(int i = 0; i< n;i++)
		{
			if(ple >= n/2)
			{
				break;
			}
			if(a[i].life2)
			{
				if(a[i].l2 > a[i].l1)
				{
					ans[1] += a[i].l2;
					a[i].life2 = 0;
					ple++;
				}
			}
		}
		sort(a,a+n,cmp1);
		ple = 0;
		for(int i = 0; i< n;i++)
		{
			if(ple >= n/2)
			{222
				break;
			}
			if(a[i].life2)
			{
				ans[1] += a[i].l1;
				a[i].life2 = 0;
				ple++;
			}
		}
		ansp[ansl] = max(ans[0],ans[1]);
		ansl++;
	}
	for(int i = 0; i < ansl; i++)cout << ansp[i] << ' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
