#include<bits/stdc++.h>
using namespace std;
int T,n,c[4][50005],r[100005];
bool b1;
struct f
{
	int a1,a2,a3;
	bool b;
}a[100005];

bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int ans=0,n1=0,n2=0,n3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			r[i]=a[i].a1;
			if(a[i].a2!=0||a[i].a3!=0)	b1=1;
		}
		if(b1==0)
		{
			sort(r+1,r+n+1,cmp);
			for(int i=1;i<=n/2;i++)	ans+=r[i];
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int t=i;
			c[1][i]=i;
			c[2][i]=i;
			c[3][i]=i;
			while(a[c[1][t-1]].a1<=a[c[1][t]].a1)
			{
				int p=c[1][t-1];
				c[1][t-1]=c[1][t];
				c[1][t-1]=p;
			}
			while(a[c[2][t-1]].a2<=a[c[2][t]].a2)
			{
				int p=c[2][t-1];
				c[2][t-1]=c[2][t];
				c[2][t-1]=p;
			}
			while(a[c[3][t-1]].a3<=a[c[3][t]].a3)
			{
				int p=c[3][t-1];
				c[3][t-1]=c[3][t];
				c[3][t-1]=p;
			}
		}
		for(int i=1;i<=n;i++)
		{
			int ma;
			if(n1<=n/2&&n2<=n/2&&n3<=n/2)
			{
				ma=max(a[c[2][i]].a2,max(a[c[1][i]].a1,a[c[3][i]].a3));
				ans+=ma;
				if(ma==a[c[1][i]].a1)
				{
					a[c[1][i]].b=1;
					n1++;
				}
				else if(ma==a[c[2][i]].a2)
				{
					a[c[2][i]].b=1;
					n2++;
				}
				else if(ma==a[c[3][i]].a3)
				{
					a[c[3][i]].b=1;
					n3++;
				}
			}	
			else if(n1>n/2)
			{
				max(a[c[2][i]].a2,a[c[3][i]].a3);
				ans+=ma;
				if(ma==a[c[2][i]].a2)
				{
					a[c[2][i]].b=1;
					n2++;
				}
				else if(ma==a[c[3][i]].a3)
				{
					a[c[3][i]].b=1;
					n3++;
				}
			}	
			else if(n2>n/2)
			{
				max(a[c[1][i]].a1,a[c[3][i]].a3);
				ans+=ma;
				if(ma==a[c[1][i]].a1)
				{
					a[c[1][i]].b=1;
					n1++;
				}
				else if(ma==a[c[3][i]].a3)
				{
					a[c[3][i]].b=1;
					n3++;
				}
			}	
			else
			{
				max(a[c[1][i]].a1,a[c[2][i]].a2);
				ans+=ma;
				if(ma==a[c[2][i]].a2)
				{
					a[c[2][i]].b=1;
					n2++;
				}
				else if(ma==a[c[1][i]].a1)
				{
					a[c[1][i]].b=1;
					n1++;
				}
			}	
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
