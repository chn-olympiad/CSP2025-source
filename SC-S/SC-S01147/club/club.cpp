#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define int long long

using namespace std;

const int N = 1e5+10;
int t,n,ans,c[N];

struct Node{
	int sat1,sat2,sat3;
	int cost;//更换代价 
}a[N];

queue<int> r[5];


signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		for(int k = 1; k <= 3; k++)	while(!r[k].empty())	r[k].pop();
		ans = 0;
		scanf("%lld",&n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld%lld%lld",&a[i].sat1,&a[i].sat2,&a[i].sat3);
			int p=max(a[i].sat1,max(a[i].sat2,a[i].sat3));
			if(p == a[i].sat1)
			{
				r[1].push(i);
				a[i].cost = p - max( a[i].sat2 , a[i].sat3 );
			}
			if(p == a[i].sat2)
			{
				r[2].push(i);
				a[i].cost = p - max( a[i].sat1 , a[i].sat3 );
			}
			if(p == a[i].sat3)
			{
				r[3].push(i);
				a[i].cost = p - max( a[i].sat1 , a[i].sat2 );
			}
			ans = ans + p;
		}
		for(int k = 1; k <= 3; k++)
		{
			if(r[k].size() > (n/2))
			{
				int l = 0;
				while(!r[k].empty())
				{
					c[++l] = a[r[k].front()].cost;
					r[k].pop();
				}
				sort(c + 1, c + l + 1);
				for(int i = 1; i <= (l-(n/2)); i++)	
				{
					ans = ans - c[i];
				}
				break ;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}