#include<iostream>
using namespace std;
int a[30005],flag[30005]={0},n,k;
int yh(int x,int y)
{
	string a1,b1,s;
	int a=x,b=y;
	int ans=0;
	a1="",b1="",s="";
	if(a==0)
	{
		a1="0";
	}
	while(a)
	{
		a1+=(a%2+'0');
		a=a/2;
	}
	if(b==0)
	{
		b1="0";
	}
	while(b)
	{
		b1+=(b%2+'0');
		b=b/2;
	}
	int la=a1.size(),lb=b1.size();
	if(la>lb)
	{
		int i;
		for(i=0;i<lb;i++)
		{
			if(a1[i]==b1[i])
			{
				s+="0";
			}
			else
			{
				s+="1";
			}
		}
		for(;i<la;i++)
		{
			if(a1[i]=='0')
			{
				s+="0";
			}
			else
			{
				s+="1";
			}
		}
	}
	else if(la<=lb)
	{
		int i;
		for(i=0;i<la;i++)
		{
			if(a1[i]==b1[i])
			{
				s+="0";
			}
			else
			{
				s+="1";
			}
		}
		for(;i<lb;i++)
		{
			if(b1[i]=='0')
			{
				s+="0";
			}
			else
			{
				s+="1";
			}
		}
	}
	int ls=s.size();
	int l=1;
	for(int i=0;i<ls;i++)
	{
		ans+=l*(s[i]-'0');
		l=l*2;
	}
	return ans;
}
int f(int start,int end)
{
	if(start==end)
	{
		if(a[start]==k)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int i,j,ans=0;
	for(i=start;i<=end;i++)
	{
		for(j=i;j<=end;j++)
		{
			int sum=a[i];
			for(int x=i+1;x<=j;x++)
			{
				sum=yh(sum,a[x]);
			}
			if(sum==k)
			{
				int s;
				if(i==start&&j==end)
				{
					s=1;
				}
				else
				{
					s=f(i,j);
				}
				ans+=s;
				i=j;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,maxi=0,j,mini=100000000;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxi)
		{
			maxi=a[i];
		}
		if(a[i]<mini)
		{
			mini=a[i];
		}
	}
	if(maxi==1&&mini==1)
	{
		if(k==1)
		{
			cout<<n;
		}
		else if(k==0)
		{
			cout<<n/2;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	int ans=f(1,n);
	cout<<ans;
	return 0;
}
