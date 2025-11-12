#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int a1,a2,a3,a_,mi;
}a[1000000];

bool cmp(Node x,Node y)
{
	return x.a_ > y.a_;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T --)
	{
		int n,c[4] = {};
		long long ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i ++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if(a[i].a1 >= a[i].a2 && a[i].a2 >= a[i].a3) a[i].a_ = a[i].a1-a[i].a2,a[i].mi = 1;
			if(a[i].a1 >= a[i].a3 && a[i].a3 >= a[i].a2) a[i].a_ = a[i].a1-a[i].a3,a[i].mi = 1;
			if(a[i].a2 >= a[i].a1 && a[i].a1 >= a[i].a3) a[i].a_ = a[i].a2-a[i].a1,a[i].mi = 2;
			if(a[i].a2 >= a[i].a3 && a[i].a3 >= a[i].a1) a[i].a_ = a[i].a2-a[i].a3,a[i].mi = 2;
			if(a[i].a3 >= a[i].a1 && a[i].a1 >= a[i].a2) a[i].a_ = a[i].a3-a[i].a1,a[i].mi = 3;
			if(a[i].a3 >= a[i].a2 && a[i].a2 >= a[i].a1) a[i].a_ = a[i].a3-a[i].a2,a[i].mi = 3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i <= n;i ++)
		{
			if(c[a[i].mi] < n/2) 
			{
				c[a[i].mi] ++;
				ans += 1ll*max(max(a[i].a1,a[i].a2),a[i].a3);
			}
			else
			{
				if(a[i].mi == 1) ans += 1ll*max(a[i].a2,a[i].a3);
				if(a[i].mi == 2) ans += 1ll*max(a[i].a1,a[i].a3);
				if(a[i].mi == 3) ans += 1ll*max(a[i].a1,a[i].a2);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
