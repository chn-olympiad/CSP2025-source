#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,s=0,c=0,x,y,o,s1=0,s2=0,f,h=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)s1++;
		else if(a[i]==0)s2++;
	}
	if(k==0&&s1+s2==n&&s2!=0)
	{
		cout<<s2;
		return 0;
	}
	if(k==1&&s1+s2==n&&s2!=0)
	{
		cout<<s1;
		return 0;
	}
	if(k==0&&s1==n)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((j-i+1)%2==0)h++;
			}
		}
		cout<<h+n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			s=0,f=1;
			for(int l=i;l<j;l++)
			{
    			if(i==l)
				{
					x=a[l],y=a[l+1];
					o=(x^y);
					s=o;
				}
				else
				{
					y=a[l+1];
     				o=(o^y);
					s=o;
				}
			}
			if(i==j)s=a[i];
			if(s!=k)continue;
			else
			{
				c++;
			}
		}
	}
	cout<<c;
	return 0;
}