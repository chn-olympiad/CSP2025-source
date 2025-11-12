#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=3e5+5;
int a[M],b[M],c[M],d[M],flag[N],ti[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j,l,T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int sum=0,x;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>a[i+n]>>a[i+2*n];
			b[i]=b[i+n]=b[i+2*n]=i;
			c[i]=1;
			c[i+n]=2;
			c[i+2*n]=3;
			flag[i]=0;
		}
		for(i=1;i<=n*3;i++)
		{
			d[i]=0;
			for(j=i;j<=n*3;j++)
			{
				if(a[i]<a[j])
				{
					swap(a[i],a[j]);
					swap(b[i],b[j]);
					swap(c[i],c[j]);
				}
			}
		}
		int y=n/2,g=n*3;
		ti[1]=1,ti[2]=1,ti[3]=1;
		for(i=1;i<=n*3;i++)
		{
			if(flag[b[i]]==0&&ti[c[i]]<=y)
			{
				sum+=a[i];
				flag[b[i]]++;
				ti[c[i]]++;
				d[i]=1;
				if(ti[c[i]]==y+1)
				{
					x=0;
					int q=b[i],p=c[i];
					for(j=i+1;j<=n*3;j++)
					{
						if(b[j]==q)
						{
							x+=a[j];
							q=-1;
						}
						if(c[j]==p)
						{
							x+=a[j];
							p=-1;
							flag[b[j]]=1;
							for(l=1;l<=g;l++)
							{
								if(b[l]==b[j]&&l!=j)
								{
									break;
								}
							}
						}
						if(p==-1&&q==-1)
						{
							break;
						}
					}
					if(d[l]==1)
					{
						sum-=a[l];
					}
					if(x>a[i]+a[l])
					{
						sum=sum-a[i]+x;
					}
					else
					{
						ti[c[l]]++;
						sum+=a[l];
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
