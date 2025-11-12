#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int sum=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			sum++;
		}
	}
	long long cnt=0,num=0;
	if(k==0 && sum==n)
	{
		cout<<n;
	}
	else
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i;j<=n;j++)
			{
				long long s1=i;
				cnt=a[i];
				while(s1<=j)
				{
					if(i==j)
					{
						cnt^=a[j];
					}
					else 
					{
						if(s1!=i)
						{
							cnt^=a[j];
						}
					}
					s1++;
				}
				if(cnt==k)
				{
					num++;
				}	
			}
		}
		cout<<num;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}