#include <cstdio>
#include <cstring>
using namespace std;
int n,a[5000],now_sum=0,now_maxl=-1,ans=0;
//int inds[5000];
bool used[5000];
const int P=998244353;
int dfs(int sticks_left,int start)
{
	if(sticks_left==0)
	{
//		printf("check : now_sum %c 2*now_maxl (%d %c %d)",(now_sum>2*now_maxl)?'>':'x',now_sum,(now_sum>2*now_maxl)?'>':'x',2*now_maxl);
		if(now_sum>2*now_maxl)
		{
			ans=(ans+1)%P;
//			printf(" , ans=%d",ans);
		}
//		putchar('\n');
		return 0;
	}
	for(int i=start;i<n;i++)
	{
		if(!used[i])
		{
//			printf("!used[%d]=true;",i);
			used[i]=true;
//			printf("now_sum=%d+%d=%d;",now_sum,a[i],now_sum+a[i]);
			now_sum+=a[i];
			int temp=now_maxl;
			if(a[i]>now_maxl)
			{
//				printf("now_maxl up to %d\n",a[i]);
				now_maxl=a[i];
			}
			else
			{
//				printf("now_maxl=%d\n",now_maxl);
			}
			dfs(sticks_left-1,i+1);
			used[i]=false;
//			printf("now_sum=%d-%d=%d;",now_sum,a[i],now_sum-a[i]);
			now_sum-=a[i];
			now_maxl=temp;
//			printf("now_maxl back to %d\n",temp);
		}
	}
	return 0;
}
int main()
{
	memset(used,false,sizeof(used));
//	memset(inds,0xff,sizeof(inds));
	freopen("polygon.in","r",stdin);
	freopen("polygin.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int sticks=3;sticks<=n;sticks++)
	{
		now_sum=0;
		now_maxl=-1;
		dfs(sticks,0);
	}
	printf("%d",ans);
	return 0;
}
