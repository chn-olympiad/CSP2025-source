//首先贪心地想，把一个选手分到满意度最高的部门，总满意度肯定最高
//但是这很有可能超过 n/2 的限制
//注意到如果真超了，最多只有一个部门会超，因为如果超两个部门，总人数必然大于 n
//考虑把超的那个部门中，记每个人最大满意度减次大满意度的值为 d
//那么考虑拿走 d 最小的几个人，直至超限部门人数恰好为 n/2
//不难发现剩下两个部门必然不会超限
//然后根本不会证明这玩意为什么最优，但样例好像可以过？
//对拍肯定是得写一下的
//笑点解析：造数据的时候忘记了 n 得是偶数
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100;
int n,a[N],b[N],c[N];
bool cmp(int x,int y)
{
	return c[x]>c[y];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<int>arr[4];
		ll su=0;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(x<y)
			{
				a[i]=y;
				b[i]=2;
			}
			else
			{
				a[i]=x;
				b[i]=1;
			}
			if(a[i]<z)
			{
				a[i]=z;
				b[i]=3;
			}
			int zz=x+y+z-a[i]-min(x,min(y,z));
			c[i]=a[i]-zz;
			arr[b[i]].push_back(i);
			su+=a[i];
			//cerr<<a[i]<<" "<<b[i]<<" "<<c[i]<<"\n";
		}
		int nn=n/2,ov=-1;
		for(int i=1;i<=3;i++)
		{
			if(arr[i].size()>nn)
			{
				ov=i;
				break;
			}
		}
		if(ov==-1)
		{
			printf("%lld\n",su);
			continue;
		}
		sort(arr[ov].begin(),arr[ov].end(),cmp);
		for(int i=nn;i<arr[ov].size();i++)
		{
			su-=c[arr[ov][i]];
		}
		printf("%lld\n",su);
	}
	return 0;
}