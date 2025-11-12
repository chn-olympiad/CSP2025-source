#include<bits/stdc++.h>
using namespace std;
int main()
{	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int sum,num=0,n,k,a[260];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum=(a[i+1]^a[i]);
		if(sum==k)
		{
			num++;
		}
		else
		{
			sum=(a[i+1]^a[i]^a[i-1]);
			if(sum==k)
			{
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
