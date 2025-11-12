#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,o[5005],k=0,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>o[i]; 
	}
	sort(o,o+n);
	for(int i=0;i<n;i++)
	{
		if(o[i]==o[i+1]) k++;
	}
	for(int i=2;i<n-k;i++)
	{
		if(998244353-sum<=i)
		{
			sum=998244353-sum;
		}
		sum+=i;
	}
	cout<<sum;
	return 0;
}
