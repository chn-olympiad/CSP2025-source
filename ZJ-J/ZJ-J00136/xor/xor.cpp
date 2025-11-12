#include<bits/stdc++.h>
using namespace std;
long long int n,k,a[500005]={},l=2,l1=0,l2=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)
		{
			l1=1;
			l=2;
		}
		else if(a[i]==1&&!l1)
		{
			l=1;
			l2=1;
		}
		else if(a[i]==0&&!l2&&!l1)
		{
			l=0;
		}
	}
	if(!l&&!l1&&!l2)
	{
		if(k!=0)
		{
			cout<<0;
			return 0;
		}
		else
		{
			cout<<n;
			return 0;
		}
	}
	else if(l==1&&!l1)
	{
		if(k>1)
		{
			cout<<0;
			return 0;
		}
		else if(k==1)
		{
			long long int h=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					h++;
				}
			}
			cout<<h;
			return 0;
		}
		else if(k==0)
		{
			long long int h=0;
			l1=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					h++;
					l1=0;
				}
				if(a[i]==1)
				{
					if(l1==0)
					{
						l1=1;
					}
					else if(l1==1)
					{
						l1=0;
						h++;
					}
				}
			}
			cout<<h;
			return 0;
		}
	}
	else
	{
		if(k==0)
		{
			long long int h=0,p=0;
			l1=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					h++;
					l1=0;
				}
				else
				{
					if(l1==0)
					{
						l1=1;
						p=a[i];
					}
					else if(l1==1&&a[i]==p)
					{
						l1=0;
						h++;
					}
					else if(l1==1&&a[i]!=p)
					{
						l1=1;
						p=a[i];
					}
				}
			}
			cout<<h;
			return 0;
		}
		else
		{
			long long int h=0,p=0;
			l1=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==k)
				{
					h++;
					l1=0;
				}
				else
				{
					if(l1==0)
					{
						l1=1;
						p=a[i];
					}
					else if(l1==1&&p^a[i]==k)
					{
						l1=0;
						h++;
					}
					else if(l1==1&&p^a[i]!=k)
					{
						p^=a[i];
					}
				}
			}
			cout<<h;
		}
	}
	return 0;
}
