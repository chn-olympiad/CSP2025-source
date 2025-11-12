#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int t,n,cnt[3];
ll a[N][3],ans;
struct ha
{
	ll val;
	int t;
}b[N];
bool cmp(ha x,ha y)
{
	return x.val<y.val;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		ans=cnt[0]=cnt[1]=cnt[2]=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		for (int i=1;i<=n;i++)
		{
			if (a[i][0]>=a[i][1] && a[i][0]>=a[i][2])ans+=a[i][0],b[i].t=0,b[i].val=a[i][0]-max(a[i][1],a[i][2]),cnt[0]++;
			else if (a[i][1]>=a[i][0] && a[i][1]>=a[i][2])ans+=a[i][1],b[i].t=1,b[i].val=a[i][1]-max(a[i][0],a[i][2]),cnt[1]++;
			else ans+=a[i][2],b[i].t=2,b[i].val=a[i][2]-max(a[i][0],a[i][1]),cnt[2]++;
		}
		sort(b+1,b+n+1,cmp);
		for (int i=0;i<=2;i++)
		{
			for (int j=1;j<=n && cnt[i]>n/2;j++)
			{
				if (b[j].t==i)ans-=b[j].val,cnt[i]--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
