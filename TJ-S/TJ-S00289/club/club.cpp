#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node
{
	int bh,f1,f2,f3;
	int maxn,c,p;
};
bool cmp(node aa,node bb)
{
//	if(aa.maxn != bb.maxn && aa.p != bb.p)
//		return aa.maxn > bb.maxn;
//	else if(aa.maxn != bb.maxn && aa.p == bb.p)
//		return aa.maxn > bb.maxn;
//	else if(aa.maxn == bb.maxn && aa.c != bb.c)
//		return aa.c < bb.c;
	if(aa.c != bb.c)
		return aa.c > bb.c;
}
int k[4] = {};
node a[100010];
int t,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n;i++)
		{
			cin >> a[i].f1 >> a[i].f2 >> a[i].f3;
			if(a[i].f1 >= a[i].f2 && a[i].f1 >= a[i].f3 && a[i].f2 >= a[i].f3)
			{
				a[i].maxn = a[i].f1;
				a[i].c = a[i].f1 - a[i].f2;
				a[i].p = 1;
			}
			else if(a[i].f1 >= a[i].f2 && a[i].f1 >= a[i].f3 && a[i].f3 >= a[i].f2)
			{
				a[i].maxn = a[i].f1;
				a[i].c = a[i].f1 - a[i].f3;
				a[i].p = 1;
			}
			else if(a[i].f2 >= a[i].f1 && a[i].f2 >= a[i].f3 && a[i].f1 >= a[i].f3)
			{
				a[i].maxn = a[i].f2;
				a[i].c = a[i].f2 - a[i].f1;
				a[i].p = 2;
			}
			else if(a[i].f2 >= a[i].f1 && a[i].f2 >= a[i].f3 && a[i].f3 >= a[i].f1)
			{
				a[i].maxn = a[i].f2;
				a[i].c = a[i].f2 - a[i].f3;
				a[i].p = 2;
			}
			else if(a[i].f3 >= a[i].f1 && a[i].f3 >= a[i].f2 && a[i].f1 >= a[i].f2)
			{
				a[i].maxn = a[i].f3;
				a[i].c = a[i].f3 - a[i].f1;
				a[i].p = 3;
			}
			else if(a[i].f3 >= a[i].f1 && a[i].f3 >= a[i].f2 && a[i].f2 >= a[i].f1)
			{
				a[i].maxn = a[i].f3;
				a[i].c = a[i].f3 - a[i].f2;
				a[i].p = 3;
			}
		}
		sort(a+1,a+n+1,cmp);
//		for(int i = 1;i<=n;i++)
//		{
//			cout << endl << a[i].maxn << endl << a[i].c;
//		}
		for(int i = 1; i <= n;i++)
		{
			if(k[a[i].p] < n/2)
			{
				ans += a[i].maxn;
				k[a[i].p] += 1;
			}
			else
			{
				ans+=a[i].maxn - a[i].c;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
