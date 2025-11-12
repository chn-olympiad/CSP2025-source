#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int i,t=0,k,n,a[1005];
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		for(i=1;i<=n;i++)
		if(a[i]==0)
		t++;
		cout<<t;
	}
	if(k==1)
	{
		for(i=1;i<=n;i++)
		if(a[i]==1)
		t++;
		cout<<t;
	}
	return 0;
} 
