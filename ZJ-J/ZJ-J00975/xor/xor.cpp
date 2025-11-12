#include<bits/stdc++.h>
using namespace std;
long long n,k,a[260],ans;
string b[260];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long r=a[i];
		for(int j=a[i];j>=0;j--)
		{
			
			if(pow(2,j)<=r)
			{
				b[i]+='1';
				r-=pow(2,j);
			}
			else
			{
				if(!b[i].empty())
				{
					b[i]+='0';
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		long long sum=0;
		for(int j=i;j<=n;j++)
		{
			if(sum==k)
			{
				ans++;
				break;
			}
			sum=sum^a[i];
			//cout<<sum;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
