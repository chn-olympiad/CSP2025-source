#include <bits/stdc++.h>
using namespace std;
int n ,m,c[505],d[505],sum;
string s;
bool ju;
int main()
{
	//Ren5Jie4Di4Ling5%
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
		if (s[i-1]=='0')
			d[i]++;
		if (c[i]==0)
			ju=true;
		d[i]+=d[i-1];
	}
	sort(c+1,c+1+n);
	if (d[n]==0)
	{
		sum=1;
		for (int i=n;i>=1;i--)
		{
			sum*=i;
			sum=sum%998244353;
		}
	}
	else if (m==1)
	{
		int l=n,r=n;
		sum=1;
		for (int i=n;i>=1;i--)
		{
			sum*=i;
			sum=sum%998244353;
		}
		int num=0,sha=true,m=1;
		for (int i=1;i<=n;i++)
		{
			
			if (s[i-1]=='1')
			{
				if (d[i]>=c[r])
				{
					sha=false;
				}
				else
				{
					while (d[i]<c[l])
						l--;
					num+=l*(n-l);
					num=num%998244353;
					r--;
				}
			}
		}
		if (sha)
		{
			if (sum>=num)
			{
				sum-=num;
			}
			else
			{
				sum=(sum+998244353-num)%998244353;
			}
		}
	}
	else if (m==n)
	{
		if (!(ju))
		{
			
		}
	}
	cout<<sum;
	return 0;
} 
