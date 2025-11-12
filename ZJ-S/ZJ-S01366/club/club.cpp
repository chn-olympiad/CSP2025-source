#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

pair <int,int> a[3];
int t,n,ans,cnt[3];

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		cnt[0] = cnt[1] = cnt[2] = ans = 0;
		priority_queue <int,vector <int>,greater <int> > q[3];
		for (int i = 1;i <= n;i++)
		{
			for (int j = 0;j < 3;j++) scanf("%d",&a[j].first),a[j].second = j;
			sort(a,a + 3);
			ans += a[2].first;
			cnt[a[2].second]++;
			q[a[2].second].push(a[2].first - a[1].first);
		}
		for (int i = 0;i < 3;i++)
			while (cnt[i] > n / 2)
			{
				cnt[i]--;
				ans -= q[i].top();
				q[i].pop();
			}
		printf("%d\n",ans);
	}
	return 0;
}
