#include<bits/stdc++.h>
using namespace std;
long long n,k,num[500001],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++)
		cin>>num[i];
	for(long long i=0;i<n;i++)
	{
		for(long long j=i;j<n;j++)
		{
			if(j==i)
			{
				if(num[i]==k){
					ans++;
					break;
				}
				continue;
			}
			long long sum=num[i]^num[i+1];
			for(long long m=1;m<j-i;m++)
				sum^=num[i+m+1];
			if(sum==k)
			{
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

