#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
bool ch(int x)
{
	int an=0,nu=0,kk=1;
	for(int i=1;i<=n;i++)
	{
		nu^=a[i];
		if(nu==k)
		{
			kk=i+1;
			an++;
			nu=0;
		}
		else if(i-kk>0)
		{
			int p=nu;
			for(int j=kk;j<i;j++)
			{
				p^=a[j];
				if(p==k)
				{
					an++;
					nu=0;
					kk=i+1;
					break;
				}
			}
		}
	}
	return an>=x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans=0,op=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		if(a[i]!=1)ans++;
		if(a[i]!=1&&a[i]!=0)op=1;
	}
	if(k==0&&ans==0)
	{
		cout<<n/2;
		return 0;
	}

	else if((k==0||k==1)&&op==0)
	{
		int num=0;
		if(k==0)
		{
			num+=ans;
			for(int i=1;i<n;i++)
			{
				if(a[i]==1&&a[i+1]==1)num++,i=i+2;
			}
			cout<<num<<endl;
			return 0;
			
		}
		if(k==1)
		{
			num+=n-ans;
			cout<<num<<endl;
			return 0;
		}
	}

	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(ch(mid))l=mid+1;
		else r=mid;
	}
	cout<<l-1;
	return 0;
}
