#include<bits/stdc++.h>
using namespace std;
int n[5009];



int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,i,j,ans=0;
	cin>>a;
	for(i=1;i<=a;i++)
	{
		cin>>n[i];
	}
	sort(n+1,n+a+1);
	int len=a,l=1,r=a,l1=l,cs=0;
	while(len>=3)
	{
		int maxx=n[r],sum=0;
		for(i=l;i<=r;i++) sum=sum+n[i];
		if(len!=a)
		{
			int temp=sum-n[l];
			for(j=1;j<l;j++)
			{
				int sum1=temp+n[j];
				if(sum1>2*maxx)
				{
					ans++;
				}
			}
		}
		
		if(sum>2*maxx)
		{
			ans++;
		}

		
		
		if(l==1)
		{
			len--;
			l1++,r=a;
			l=l1;
		}else
		{
			l--,r--;
		}
	}
	cout<<ans;
	return 0;
 } 
