#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
}a[100005];
long long ans;
bool flag=0;
bool cmp(node x,node y)
{
	return x.x>y.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",a[i].x,a[i].y,a[i].z);
			if(a[i].y!=0) flag=1;
		}
		sort(a+1,a+n+1,cmp);
		if(!flag)
		{
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
