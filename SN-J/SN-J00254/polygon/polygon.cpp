#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,ans=0;
int a[5005],fr[5005]={0}; 
int cou(int a,int b)
{
	int a1=1,b1=1;
	for(int i=0;i<b;i++)a1*=a-i;
	for(int i=1;i<=b;i++)b1*=i;
	return a1/b1;
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)fr[i]=a[i]+fr[i-1];
	int l=1,r=3,l0=1;
	for(int i=3;i<=n;i++)
	{
		l=1,r=3,l0=1;
		while(r<=i)
		{
			if(fr[r]-fr[l-1]>2*a[i])
			{
				if(l+1<=r-2)l++;
				else 
				{
					ans++;
					if(r+1<=i)
					{
						for(int j=1;j<l-l0+1;j++)
						{
							ans+=cou(l-l0+1,j);
							if(ans>=998244353)ans%=998244353;
						}
						l0=l;
					}
					r++;
				}
			}
			else
			{
				if(r+1<=i)
				{
					for(int j=0;j<=l-l0+1;j++)
					{
						ans+=cou(l-l0+1,j);
						if(ans>=998244353)ans-=998244353;
					}
					l0=l;
				}
				r++;
			}
		}
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
