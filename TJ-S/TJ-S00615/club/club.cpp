#include<bits/stdc++.h>

using namespace std;

int t;

struct
{
	int t1,t2,t3;
}a[100005];

int a1,a2,a3;

cmp(int x,int y)
{
	if(a[x].t1>a[y].t1) return a[x].t1 < a[y].t1;
	else if(a[x].t2>a[y].t2) return a[x].t2 < a[y].t2;
	else return a[x].t3 < a[y].t3;
};

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++)
	{
		int n,ans = 0;
		a1=0,a2=0,a3=0;
		int maxx=n/2;
		for(int j = 1;j <= n;j++)
		{
			cin >> a[i].t1;
			cin >> a[i].t2;
			cin >> a[i].t3;
		}
		sort(a+1,a+n+1,cmp);
		for(int j = 1;j <= n;j++)
		{
			if(a[j].t1 >= a[j].t2 and a[j].t1 >= a[j].t3 and a1 < maxx) ans+=a[j].t1;
			else if(a[j].t2 >= a[j].t1 and a[j].t2 >= a[j].t3 and a2 < maxx) ans+=a[j].t2;
			else if(a[j].t3 >= a[j].t1 and a[j].t3 >= a[j].t2 and a3 < maxx) ans+=a[j].t3;
			else
			{
				if(a[j].t1 > a[j].t2 and a1 < maxx or a[j].t1 > a[j].t3 and a1 < maxx) ans+=a[j].t1;
				else if(a[j].t2 > a[j].t1 and a2 < maxx or a[j].t2 > a[j].t3 and a2 < maxx) ans+=a[j].t2;
				else if(a[j].t3 > a[j].t2 and a3 < maxx or a[j].t3 > a[j].t2 and a3 < maxx) ans+=a[j].t3;
				else
				{
					if(a1 < maxx) ans+=a[j].t1;
					if(a2 < maxx) ans+=a[j].t2;
					else ans+=a[j].t3;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
