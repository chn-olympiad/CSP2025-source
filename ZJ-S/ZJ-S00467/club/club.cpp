#include<bits/stdc++.h>
using namespace std;
long long n,maxn;
long long ans[100007];
long long ansn=-999999;
long long mm1,mm2,mm3;
struct myd
{
	bool flag=false;
	long long a,b,c;
}a[100005];
bool cmp(myd a,myd b)
{
	if(a.a!=b.a)
	{
		return a.a>b.a;	
	}
	if(a.b!=b.b)
	{
		return a.b>b.b;
	}
	return a.c>b.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		mm1=0;
		mm2=0;
		mm3=0;
		ansn=0;
		maxn=n/2;
		
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+1+n,cmp);			
		for (int i=1;i<=6;i++)
		{
			ans[i]=0;
		}		
		for (int i=1;i<=n;i++)
		{
			a[i].flag=false;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=6;j++)
			{
				if(j==1)
				{
					if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&a[i].flag==false&&mm1<maxn)
					{
						mm1++;
						a[i].flag=true;
						ans[j]+=a[i].a;
						
					}
					else if(a[i].b>=a[i].a&&a[i].b>=a[i].c&&a[i].flag==false&&mm2<maxn)
					{
						mm2++;
						a[i].flag=true;
						ans[j]+=a[i].b;
					}
					else if(a[i].c>=a[i].a&&a[i].c>=a[i].b&&a[i].flag==false&&mm3<maxn)
					{
						mm3++;
						a[i].flag=true;
						ans[j]+=a[i].c;
					}
						
				}
				else if(j==2)
				{
					if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&a[i].flag==false&&mm1<maxn)
					{
						mm1++;
						a[i].flag=true;
						ans[j]+=a[i].a;
					}
					else if(a[i].c>=a[i].a&&a[i].c>=a[i].b&&a[i].flag==false&&mm3<maxn)
					{
						mm3++;
						a[i].flag=true;
						ans[j]+=a[i].c;
					}					
					else if(a[i].b>=a[i].a&&a[i].b>=a[i].c&&a[i].flag==false&&mm2<maxn)
					{
						mm2++;
						a[i].flag=true;
						ans[j]+=a[i].b;
					}	
				}
				else if(j==3)
				{
					if(a[i].b>=a[i].a&&a[i].b>=a[i].c&&a[i].flag==false&&mm2<maxn)
					{
						mm2++;
						a[i].flag=true;
						ans[j]+=a[i].b;
					}				
					else if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&a[i].flag==false&&mm1<maxn)
					{
						mm1++;
						a[i].flag=true;
						ans[j]+=a[i].a;
					}
					else if(a[i].c>=a[i].a&&a[i].c>=a[i].b&&a[i].flag==false&&mm3<maxn)
					{
						mm3++;
						a[i].flag=true;
						ans[j]+=a[i].c;
					}		
				}
				else if(j==4)
				{
					if(a[i].b>=a[i].a&&a[i].b>=a[i].c&&a[i].flag==false&&mm2<maxn)
					{
						mm2++;
						a[i].flag=true;
						ans[j]+=a[i].b;
					}		
					else if(a[i].c>=a[i].a&&a[i].c>=a[i].b&&a[i].flag==false&&mm3<maxn)
					{
						mm3++;
						a[i].flag=true;
						ans[j]+=a[i].c;
					}								
					else if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&a[i].flag==false&&mm1<maxn)
					{
						mm1++;
						a[i].flag=true;
						ans[j]+=a[i].a;
					}
				}
				else if(j==5)
				{
					if(a[i].c>=a[i].a&&a[i].c>=a[i].b&&a[i].flag==false&&mm3<maxn)
					{
						mm3++;
						a[i].flag=true;
						ans[j]+=a[i].c;
					}					
					else if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&a[i].flag==false&&mm1<maxn)
					{
						mm1++;
						a[i].flag=true;
						ans[j]+=a[i].a;
					}
					else if(a[i].b>=a[i].a&&a[i].b>=a[i].c&&a[i].flag==false&&mm2<maxn)
					{
						mm2++;
						a[i].flag=true;
						ans[j]+=a[i].b;
					}
				}
				else if(j==6)
				{
					if(a[i].c>=a[i].a&&a[i].c>=a[i].b&&a[i].flag==false&&mm3<maxn)
					{
						mm3++;
						a[i].flag=true;
						ans[j]+=a[i].c;
					}		
					else if(a[i].b>=a[i].a&&a[i].b>=a[i].c&&a[i].flag==false&&mm2<maxn)
					{
						mm2++;
						a[i].flag=true;
						ans[j]+=a[i].b;
					}									
					else if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&a[i].flag==false&&mm1<maxn)
					{
						mm1++;
						a[i].flag=true;
						ans[j]+=a[i].a;
					}
				}
				for (int k=1;k<=6;k++)
				{
					ansn=max(ansn,ans[k]);
				}

			}
		}
		cout<<ansn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}