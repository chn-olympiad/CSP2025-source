#include<bits/stdc++.h>
using namespace std;
int a[100005]={0},b[100005]={0},c[100005]={0},p[100005],p2[100005],p1[100005]={0};
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int a1=0,b1=0,c1=0;
		int n;
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i])
			{
				p[i]=a[i];p2[i]=1;
				a1++;
			 } 
			 else if(b[i]>=a[i]&&b[i]>=c[i])
			 {
			 	p[i]=b[i];p2[i]=2;
			 	b1++;
			 }
			 else if(c[i]>=a[i]&&c[i]>=b[i])
			 {
			 	p[i]=c[i];p2[i]=3;
			 	c1++;
			 }
		}
		int m=0;
		for(int i=1;i<=n;i++)
		{
			m+=p[i];
		}
		if(a1<=n/2&&b1<=n/2&&c1<=n/2)
		{
			cout<<m<<endl;
			continue;
		}
		int don=0;
		int di[100005]={0};
		if(a1>=n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(p2[i]==1)
				{
					p1[i]=p[i];
					di[i]=i;
				
					don++;
				}
			}
			for(int i=1;i<=don;i++)
			{
				for(int j=i+1;j<=don;j++)
				{
					if(p1[j]<p1[i])
					{
						swap(p1[j],p1[i]);
						swap(di[j],di[i]);
					}
				}
			}
			int dt[100005]={0};
			int x=0,y=0;
			for(int i=1;i<=don;i++)
			{
				if(m-(a[di[i]]-c[di[i]])>=m-(a[di[i]]-b[di[i]]))
				{
					dt[i]=m-(a[di[i]]-c[di[i]]);
				}
				else
				{
					dt[i]=m-(a[di[i]]-b[di[i]]);
				}
			}
				
			sort(dt+1,dt+don+1,cmp);
			int sum=0;
			for(int i=1;i<=a1-n/2;i++)
			{
				sum+=m-dt[i];
			}
			
			cout<<m-sum<<endl;
		}
		else if(b1>=n/2)
		{
	
			for(int i=1;i<=n;i++)
			{
				if(p2[i]==2)
				{
					p1[i]=p[i];
					di[i]=i;
					don++;
				}
			}
			
			for(int i=1;i<=don;i++)
			{
				for(int j=i+1;j<=don;j++)
				{
					if(p1[j]<p1[i])
					{
						swap(p1[j],p1[i]);
						swap(di[j],di[i]);
					}
				}
			}
			int dt[100005]={0};
			int x=0,y=0;
			for(int i=1;i<=don;i++)
			{
				if(m-(b[di[i]]-c[di[i]])>=m-(b[di[i]]-a[di[i]]))
				{
					dt[i]=m-(b[di[i]]-c[di[i]]);
				}
				else
				{
					dt[i]=m-(b[di[i]]-a[di[i]]);
				}
				
			}
				
			sort(dt+1,dt+don+1,cmp);
			int sum=0;
			for(int i=1;i<=b1-n/2;i++)
			{
				sum+=m-dt[i];
			}
			
			cout<<m-sum<<endl;
		}
		else if(c1>=n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(p2[i]==3)
				{
					p1[i]=p[i];
					di[i]=i;
				
					don++;
				}
			}
			for(int i=1;i<=don;i++)
			{
				for(int j=i+1;j<=don;j++)
				{
					if(p1[j]<p1[i])
					{
						swap(p1[j],p1[i]);
						swap(di[j],di[i]);
					}
				}
			}
			int dt[100005]={0};
			int x=0,y=0;
			for(int i=1;i<=don;i++)
			{
				if(m-(c[di[i]]-a[di[i]])>=m-(c[di[i]]-b[di[i]]))
				{
					dt[i]=m-(c[di[i]]-a[di[i]]);
				}
				else
				{
					dt[i]=m-(c[di[i]]-b[di[i]]);
				}
			}
				
			sort(dt+1,dt+don+1,cmp);
			int sum=0;
			for(int i=1;i<=c1-n/2;i++)
			{
				sum+=m-dt[i];
			}
			cout<<m-sum<<endl;
		}
	}
}
