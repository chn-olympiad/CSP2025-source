#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,t,ans,x,y,z;
struct node{
	int v1,v2,v3;
	int mx,mz,cha;
}a[N];
bool cmp(node x,node y)
{
	return x.cha>y.cha;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=x=y=z=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].v1>>a[i].v2>>a[i].v3;
			a[i].mx=max(a[i].v1,max(a[i].v2,a[i].v3));
			a[i].mz=a[i].v1+a[i].v2+a[i].v3-a[i].mx-min(a[i].v1,min(a[i].v2,a[i].v3));
			a[i].cha=a[i].mx-a[i].mz;
		}
		sort(a+1,a+n+1,cmp);
		int j=1;
		while(x<n/2&&y<n/2&&z<n/2&&j<=n)
		{
			
			ans+=a[j].mx;
			if(a[j].mx==a[j].v1)
				x++;
			else if(a[j].mx==a[j].v2)
				y++;
			else
				z++;
			j++;
		}
		if(x>=n/2)
		{
			while(j<=n)
			{
				if(a[j].mx==a[j].v1)
					ans+=a[j].mz;
				else
					ans+=a[j].mx;
				j++;
			}
		}
		else if(y>=n/2)
		{
			while(j<=n)
			{
				if(a[j].mx==a[j].v2)
					ans+=a[j].mz;
				else
					ans+=a[j].mx;
				j++;
			}
		}
		else if(z>=n/2)
		{
			while(j<=n)
			{
				if(a[j].mx==a[j].v3)
					ans+=a[j].mz;
				else
					ans+=a[j].mx;
				j++;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//club
