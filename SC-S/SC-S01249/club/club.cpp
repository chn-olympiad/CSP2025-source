#include<bits/stdc++.h>
using namespace std;
int a [100100][5],club[4],t,n;
int max2=0,max1=0;
int gg(int num)
{
	for(int i=0;i<3;i++)
	{
		if(num<n&&club[i]+1<=n/2)
		{
			max2+=a[num][i];
			club[i]++;
			gg(num+1);
			max2-=a[num][i];
			club[i]--;
		}
		else if(num==n&&club[i]+1<=n/2)
		{
			max2+=a[num][i];
			club[i]++;
			if(max2>max1) max1=max2;
			max2-=a[num][i];
			club[i]--;
		}
		
	}
	return max1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	 scanf("%d",&t);
	for(int pp=0;pp<t;pp++)
	{
		 scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i][0]);
			scanf("%d",&a[i][1]);
			scanf("%d",&a[i][2]);
		}
		 max2=0,max1=0;
		int ff=gg(1);
		printf("%d\n",ff);	
	}
	return 0;
}