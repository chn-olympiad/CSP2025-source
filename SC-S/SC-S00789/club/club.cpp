#include <bits/stdc++.h>
using namespace std;
int q, ans;
int n;
struct Club
{
	int v;
	int id;
} a[100050], b[100050], c[100050];
bool vis[100050];
int cnt1, cnt2 , cnt3;
bool cmp(Club x, Club y)
{
	if(x.v  == y.v)
	    return x.id < y.id;
	return x.v > y.v;
}
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout); 
	cin >> q;
	while(q --)
	{
		ans = 0;
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for(int i = 1; i <= n;i ++)
		{
			cin >> a[i].v >> b[i].v >> c[i].v;
			a[i].id = i;
			b[i].id = i;
			c[i].id = i;
		}
		sort(a + 1, a + 1 + n, cmp);
		sort(b + 1, b + 1 + n, cmp);
		sort(c + 1, c + 1 + n, cmp);
		cnt1 = cnt2 = cnt3 = 0;
		for(int i = 1;i <= n;i ++)
		{
			if(a[i].v >= b[i].v && a[i].v >= c[i].v)
			{
				if(!vis[a[i].id] && cnt1 < n / 2)
			    {
		    		ans += a[i].v;
		    		cnt1 ++;
		    		vis[a[i].id] = 1;
		    	}
		    	if(b[i].v >= c[i].v)
		    	{
		    		if(!vis[b[i].id] && cnt2 < n / 2)
		    		{
		    			ans += b[i].v;
		    			cnt2 ++;
		    			vis[b[i].id] = 1;
		    		}
		    		if(!vis[c[i].id] && cnt3 < n / 2)
		    		{
		    			ans += c[i].v;
		    			cnt3 ++;
		    			vis[c[i].id] = 1;
		    		}
				}
				else
				{
					if(!vis[c[i].id] && cnt3 < n / 2)
		    		{
		    			ans += c[i].v;
		    			cnt3 ++;
		    			vis[c[i].id] = 1;
		    		}
					if(!vis[b[i].id] && cnt2 < n / 2)
		    		{
		    			ans += b[i].v;
		    			cnt2 ++;
		    			vis[b[i].id] = 1;
		    		}
				}
			}
			else if (b[i].v > a[i].v && b[i].v > a[i].v)
			{
				if(!vis[b[i].id] && cnt2 < n / 2)
			    {
		    		ans += b[i].v;
		    		cnt2 ++;
		    		vis[b[i].id] = 1;
		    	}
		    	if(a[i].v >= c[i].v)
		    	{
		    		if(!vis[a[i].id] && cnt1 < n / 2)
		    		{
		    			ans += a[i].v;
		    			cnt1 ++;
		    			vis[a[i].id] = 1;
		    		}
		    		if(!vis[c[i].id] && cnt3 < n / 2)
		    		{
		    			ans += c[i].v;
		    			cnt3 ++;
		    			vis[c[i].id] = 1;
		    		}
				}
				else
				{
					if(!vis[c[i].id] && cnt3 < n / 2)
		    		{
		    			ans += c[i].v;
		    			cnt3 ++;
		    			vis[c[i].id] = 1;
		    		}
					if(!vis[a[i].id] && cnt1 < n / 2)
		    		{
		    			ans += a[i].v;
		    			cnt1 ++;
		    			vis[a[i].id] = 1;
		    		}
				}
			}
			else
			{
				if(!vis[c[i].id] && cnt3 < n / 2)
			    {
		    		ans += c[i].v;
		    		cnt3 ++;
		    		vis[c[i].id] = 1;
		    	}
		    	if(a[i].v >= b[i].v)
		    	{
		    		if(!vis[a[i].id] && cnt1 < n / 2)
		    		{
		    			ans += a[i].v;
		    			cnt1 ++;
		    			vis[a[i].id] = 1;
		    		}
		    		if(!vis[b[i].id] && cnt2 < n / 2)
		    		{
		    			ans += b[i].v;
		    			cnt2 ++;
		    			vis[b[i].id] = 1;
		    		}
				}
				else
				{
					if(!vis[b[i].id] && cnt2 < n / 2)
		    		{
		    			ans += b[i].v;
		    			cnt2 ++;
		    			vis[b[i].id] = 1;
		    		}
					if(!vis[a[i].id] && cnt1 < n / 2)
		    		{
		    			ans += a[i].v;
		    			cnt1 ++;
		    			vis[a[i].id] = 1;
		    		}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}