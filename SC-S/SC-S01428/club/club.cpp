#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int a[N],b[N],c[N];
int maxa[N],maxb[N],maxc[N];

int mp(int a[],int b)
{
	for(int i=0;i<=b;i++)
	{
		for(int j=i;j<=b;j++)
		{
			if(a[i]<a[j])
				swap(a[i],a[j]);
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freoprn("club.out","w",stdout);
	int t,n;
	int sum=0,nx=1;
	int A=0,B=0,C=0;
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]!=0 && b[i]!=0 && c[i]!=0)
				continue;
			else
			{
				if(a[i]>b[i] && a[i]>c[i])
				{
					maxa[i]=a[i];
				}
				else if(b[i]>a[i] && b[i]>c[i])
				{
					maxb[i]=b[i];
				}
				else
					maxc[i]=c[i];
			}	
		}
		mp(maxa,n);
		mp(maxb,n);
		mp(maxc,n);
		for(int i=0;i<n/2;i++)
		{
			if(maxa[i]==0)
				break;
			else
			{
				sum+=maxa[i];
				nx++;
				A++;
			}
		}
		for(int i=0;i<n/2;i++)
		{
			if(maxb[i]==0)
				break;
			else
			{
				sum+=maxb[i];
				nx++;
				B++;
			}
		}
		for(int i=0;i<n/2;i++)
		{
			if(maxc[i]==0 || nx==n)
				break;
			else
			{
				sum+=maxc[i];
				nx++;
				C++;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(maxa[i]==0 && maxb[i]==0 && maxc[i]==0)
			{
				if(a[i]>b[i] && a[i]>c[i])
				{
					maxa[i]=a[i];
				}
				else if(b[i]>a[i] && b[i]>c[i])
				{
					maxb[i]=b[i];
				}
				else if(c[i]>a[i] && c[i]>b[i])
					maxc[i]=c[i];
			}
		}
		mp(maxa,n);
		mp(maxb,n);
		mp(maxc,n);
		while(n-nx>=0)
		{
			for(int i=0;i<n/2;i++)
			{
				if(maxa[i]==0 || n-nx==0 || A>=n/2)
					break;
				else
				{
					sum+=maxa[i];
					nx++;
					A++;
				}
			}	
			for(int i=0;i<n/2;i++)
			{
				if(maxb[i]==0 || n-nx==0 || B>=n/2)
					break;
				else
				{
					sum+=maxb[i];
					nx++;
					B++;
				}
			}
			for(int i=0;i<n/2;i++)
			{
				if(maxc[i]==0 || n-nx==0)
					break;
				else
				{
					sum+=maxc[i];
					nx++;
					C++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}