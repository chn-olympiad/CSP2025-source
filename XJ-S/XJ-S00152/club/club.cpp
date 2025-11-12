#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int Max[100005],flag[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,T,s=0,Maxn,ans=0,Maxs=0,x,y,z,i,j;
	cin>>T;
	while(T--)
	{
		cin>>n;
		Maxn=n/2;
		ans=0;
		s=0;
		x=0;
		y=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			Max[i]=a[i];
			flag[i]=1;
			if(b[i]>Max[i])
			{
				Max[i]=b[i];
				flag[i]=2;
			} 
			if(c[i]>Max[i])
			{
				Max[i]=c[i];
				flag[i]=3;
			}
		}
		for(i=1;i<=n-1;i++)
		{
			for(j=1;j<=n-i;j++)
			{
				if(Max[j]<Max[j+1])
				{
					swap(Max[j],Max[j+1]);
					swap(flag[j],flag[j+1]);
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(flag[i]==1)
			{
				if(x<Maxn)
				{
					ans+=Max[i];
				}
				x++;
			}
			else if(flag[i]==2)
			{
				if(y<Maxn)
				{
					ans+=Max[i];
				}
				y++; 
			}
			else if(flag[i]==3)
			{
				if(z<Maxn)
				{
					ans+=Max[i];
				}
				z++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
