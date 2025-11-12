#include <iostream>
#include <algorithm>
#include <cstring>
#define big long long
using namespace std;
big T,n;
// 对于每个人，尽可能分到对他来说最大的地方，如果不能，就选次大，以此类推
struct ID{
	big id,val;
};
struct Node{
	ID p[4];
	big maxv;
}pos[100005];
bool cmp(Node l,Node r)
{
	if(l.p[1].val-l.p[2].val != r.p[1].val-r.p[2].val)
		return l.p[1].val-l.p[2].val > r.p[1].val-r.p[2].val;
	return l.p[2].val-l.p[3].val > r.p[2].val-r.p[3].val;
}
bool cmp2(ID l,ID r)
{
	return l.val > r.val;
}
big num[5],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		memset(num,0,sizeof num); ans = 0;
		for(big i = 1;i <= n;i++) pos[i].maxv = 0;
		for(big i = 1,x,y,z;i <= n;i++)
		{
			scanf("%lld %lld %lld",&x,&y,&z);
			ID tmp[4];
			tmp[1] = {1,x};
			tmp[2] = {2,y};
			tmp[3] = {3,z};
			sort(tmp+1,tmp+4,cmp2);
			for(big j = 1;j <= 3;j++)
			{
				pos[i].p[j] = tmp[j];
			}
			pos[i].maxv = max({x,y,z});
		}
		sort(pos+1,pos+n+1,cmp);
		for(big i = 1;i <= n;i++)
		{
			big pp = 0;
			for(big j = 1;j <= n;j++)
			{
				if(num[pos[i].p[j].id] < (n>>1))
				{
					pp = j;
					break;
				}
			}
			num[pos[i].p[pp].id]++;
			ans += pos[i].p[pp].val;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
