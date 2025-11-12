#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,t,a1[100010],a2[100010],a3[100010],b1,b2,b3,c1,c2,c3,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		ans=0,c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&b1,&b2,&b3);
			if(b1>=b2&&b1>=b3)
			{
				ans+=b1;
				a1[++c1]=min(b1-b2,b1-b3);
			}
			else if(b2>=b1&&b2>=b3)
			{
				ans+=b2;
				a2[++c2]=min(b2-b1,b2-b3);
			}
			else if(b3>=b1&&b3>=b2)
			{
				ans+=b3;
				a3[++c3]=min(b3-b1,b3-b2);
			}
		}
		if(c1>n/2)
		{
			sort(a1+1,a1+1+c1);
			for(int i=1;i<=c1-n/2;i++) ans-=a1[i];
		}
		else if(c2>n/2)
		{
			sort(a2+1,a2+1+c2);
			for(int i=1;i<=c2-n/2;i++) ans-=a2[i];
		}
		else if(c3>n/2)
		{
			sort(a3+1,a3+1+c3);
			for(int i=1;i<=c3-n/2;i++) ans-=a3[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
