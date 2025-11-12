#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int a[10005][5],choose[5],d[10005],ans=0,maxs[10005],chazhi[10005],m=0,k=0;
		for(int i=1;i<=5;i++) choose[i]=0;
		for(int i=1;i<=10005;i++) d[i]=0;
		for(int i=1;i<=10005;i++) maxs[i]=0;
		for(int i=1;i<=10005;i++) chazhi[i]=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int max=0,min=20005,mins=0;
			for(int j=1;j<=3;j++)
			cin>>a[i][j];
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>max)
				{
					max=a[i][j];
					maxs[i]=j;
				}
				if(a[i][j]<min)
				{
					min=a[i][j];
					mins=j;
				}
			}
			d[i]=max-a[i][6-maxs[i]-mins];
			choose[maxs[i]]++;
			ans+=max;
		}
		for(int i=1;i<=3;i++)
		{
			if(choose[i]>(n/2))
			{
				m=choose[i]-(n/2);
				for(int j=1;j<=n;j++)
				{
					if(maxs[j]==i)
					{
						k++;
						chazhi[k]=d[j];
					}
				}
			}
		}
		sort(chazhi+1,chazhi+k+1);
		for(int i=1;i<=m;i++)
		{
			ans-=chazhi[i];
		}
		cout<<ans<<endl;
		for(int i=1;i<=5;i++) choose[i]=0;
		for(int i=1;i<=10005;i++) d[i]=0;
		for(int i=1;i<=10005;i++) maxs[i]=0;
		for(int i=1;i<=10005;i++) chazhi[i]=0;
	}
	return 0;
}