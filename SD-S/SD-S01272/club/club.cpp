#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct Node{
	int x,y,z,mf,ms,fr,se,ls;
}a[N];
int T,n,ans;
bool cmp(Node c,Node d)
{
	return c.mf-c.ms>d.mf-d.ms;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].mf=max(a[i].x,max(a[i].y,a[i].z));
			int mn=min(a[i].x,min(a[i].y,a[i].z));
			if(a[i].x==a[i].mf)
			{
				a[i].fr=1;
			}
			else if(a[i].y==a[i].mf)
			{
				a[i].fr=2;
			}
			else
			{
				a[i].fr=3;
			}
			if(a[i].x==mn)
			{
				a[i].ls=1;
			}
			else if(a[i].y==mn)
			{
				a[i].ls=2;
			}
			else
			{
				a[i].ls=3;
			}
			if(a[i].fr==a[i].ls)
			{
				a[i].ls=a[i].fr+1;
			}
			if(a[i].fr==1&&a[i].ls==2||a[i].fr==2&&a[i].ls==1)
			{
				a[i].ms=a[i].z;
				a[i].se=3;
			}
			else if(a[i].fr==1&&a[i].ls==3||a[i].fr==3&&a[i].ls==1)
			{
				a[i].ms=a[i].y;
				a[i].se=2;
			}
			else
			{
				a[i].ms=a[i].x;
				a[i].se=1;
			}
		}
		sort(a+1,a+n+1,cmp);
		int tot1=0,tot2=0,tot3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].fr==1)
			{
				if(tot1>=n/2)
				{
					if(a[i].se==2)
					{
						ans+=a[i].y;
						tot2++;
					}
					else
					{
						ans+=a[i].z;
						tot3++;
					}
				}
				else
				{
					ans+=a[i].x;
					tot1++;
				}
			}
			else if(a[i].fr==2)
			{
				if(tot2>=n/2)
				{
					if(a[i].se==1)
					{
						ans+=a[i].x;
						tot1++;
					}
					else
					{
						ans+=a[i].z;
						tot3++;
					}
				}
				else
				{
					ans+=a[i].y;
					tot2++;
				}
			}
			else
			{
				if(tot3>=n/2)
				{
					if(a[i].se==2)
					{
						ans+=a[i].y;
						tot2++;
					}
					else
					{
						ans+=a[i].x;
						tot1++;
					}
				}
				else
				{
					ans+=a[i].z;
					tot3++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
