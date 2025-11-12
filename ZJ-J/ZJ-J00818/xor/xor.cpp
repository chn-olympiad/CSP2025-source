#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],num[500001],h,l;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num[i]=num[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=l;j<i;j++)
		{
			if(a[i]==k)
			{
				h++;
				l=i;
				break;
			}
			if(a[i]==0)
			{
				break;
			}
			int sum=~(~num[i]&~num[j]);
			if(sum==k)
			{
				h++;
				l=i;
				break;
			}
		}
	}
	cout<<h;
	return 0;
}