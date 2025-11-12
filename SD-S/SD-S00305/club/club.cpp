#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t,a[N],b[N],c[N],q[N],num,w[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		num = 0;
		int n,cnt1 = 0,cnt2 = 0,cnt3 = 0;
		scanf("%d",&n);
		long long ans = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			int p = max(a[i],max(b[i],c[i]));
			ans += p;
			if(a[i] >= b[i] && a[i] >= c[i])
			{
				w[i] = 1;
				cnt1++;
			}
			else if(b[i] >= c[i] && b[i] >= a[i]) 
			{
				w[i] = 2;
				cnt2++;
			}
			else if(c[i] >= b[i] && c[i] >= a[i]) 
			{
				w[i] = 3;
				cnt3++;
			}
		}
		if(cnt1 > n / 2)
		{
			for(int i = 1;i <= n;i++)
			{
				if(w[i] != 1) continue;
				q[++num] = min(a[i] - b[i],a[i] - c[i]);
			}
			sort(q + 1,q + num + 1);
			for(int i = 1;i <= cnt1 - n / 2;i++) ans -= q[i];
		}
		if(cnt2 > n / 2)
		{
			for(int i = 1;i <= n;i++)
			{
				if(w[i] != 2) continue;
				q[++num] = min(b[i] - a[i],b[i] - c[i]);
			}
			sort(q + 1,q + num + 1);
			for(int i = 1;i <= cnt2 - n / 2;i++) ans -= q[i];
		}
		if(cnt3 > n / 2)
		{
			for(int i = 1;i <= n;i++)
			{
				if(w[i] != 3) continue;
				q[++num] = min(c[i] - a[i],c[i] - b[i]);
			}
			sort(q + 1,q + num + 1);
			for(int i = 1;i <= cnt3 - n / 2;i++) ans -= q[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
