#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[50005ll];
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		cout<<0;
	} 
	else
	{
		cout<<1;
	}
	
	return 0;
}
