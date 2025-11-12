#include<bits/stdc++.h>
using namespace std;
int n,t;
struct poi{
	int s,x;
}maxx[100010];
struct node{
	int sa1,sa2,sa3;
}a[100010];
bool cmp(poi x,poi y)
{
	return x.x>y.x;
}
int main()
{
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int ans;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i].sa1,&a[i].sa2,&a[i].sa3);
			maxx[i].x=max(a[i].sa3,max(a[i].sa1,a[i].sa2));	
		}
		sort(maxx+1,maxx+1+n,cmp);
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i].sa2!=0 || a[i].sa3!=0) 
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			for(int i=1;i<=n/2;i++)
			{
				ans+=maxx[i].x;
			}	
		}
		else
		{
			for(int i=1;i<=n;i++) ans+=maxx[i].x;
		}
		
		printf("%d",ans);
	}
	
	
	return 0;
}