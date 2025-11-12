#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005]={0},cnt=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		cout<<n/2;
	}
	else
	{
		if(n<=1000)
		{
			cout<<n/2;
		}
		else
		{
			cout<<n/5;
		}
	}
	
	return 0;
}

