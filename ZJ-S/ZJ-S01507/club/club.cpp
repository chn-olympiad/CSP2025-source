#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int n;
struct node{
	int amaxn,a2maxn,cha,id;
}a[N];

bool cmp(node aa,node bb)
{
	if(aa.cha == bb.cha) return aa.amaxn > bb.amaxn;
	return aa.cha > bb.cha;

}

void solve()
{
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[i].amaxn = max(x,max(y,z));
		if(a[i].amaxn== x) a[i].a2maxn = max(y,z),a[i].id = 1;
		else if(a[i].amaxn == y) a[i].a2maxn = max(x,z) , a[i].id = 2;
		else if(a[i].amaxn == z)a[i].a2maxn = max(x,y),a[i].id = 3;
		a[i].cha = a[i].amaxn - a[i].a2maxn;
		
	}
	sort(a+1,a+n+1,cmp);
	
	int ans = 0;
	int sum1 = 0,sum2 = 0,sum3 = 0;
	

	for(int i = 1;i <= n;i++)
	{
		if(a[i].id == 1)
		{
			if(sum1 < n/2)
			{
				ans += a[i].amaxn;
				sum1++;
			}
			else
			{
				int t1 = a[i-1].amaxn + a[i].a2maxn;
				int t2 = a[i-1].a2maxn + a[i].amaxn;
				if(t2 > t1) ans = ans - a[i-1].amaxn + t2;
				else ans = ans + a[i].a2maxn; 
			}
		}
		if(a[i].id == 2)
		{
			if(sum2 < n/2)
			{
				ans += a[i].amaxn;
				sum2++;
			}
			else
			{
				int t1 = a[i-1].amaxn + a[i].a2maxn;
				int t2 = a[i-1].a2maxn + a[i].amaxn;
				if(t2 > t1) ans = ans - a[i-1].amaxn + t2;
				else ans = ans + a[i].a2maxn; 
			}
		}
		if(a[i].id == 3)
		{
			if(sum3 < n/2)
			{
				ans += a[i].amaxn;
				sum3++;
			}
			else
			{
				int t1 = a[i-1].amaxn + a[i].a2maxn;
				int t2 = a[i-1].a2maxn + a[i].amaxn;
				if(t2 > t1) ans = ans - a[i-1].amaxn + t2;
				else ans = ans + a[i].a2maxn; 
			}
		}
	}
	cout<<ans<<"\n";
	
}


signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}

