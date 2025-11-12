#include<bits/stdc++.h>
using namespace std;
int n,a[500010],ans,s[1010][1010];
long long k,sum,tot,maxtot;
long long check()
{
	for(int t=1;t<=n;t++)
	{
		tot=0;
		for(int i=t;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(s[i][j]==k)
				{
					tot++;
					j=n+1;
					i=j+1;
					
				}
				
			}
		}
		maxtot=max(tot,maxtot);
	}
	return maxtot;
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		s[i][i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i<j)
			{
				s[i][j]=s[i][j-1]^a[j];
				
			}
		}
		
	}
	
	cout << check();
	
	
	
	
	
	
	
	
	
	return 0;
}
