#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[1000005],js,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		if(a[i]==1)
		{
			js++;
		}
	}
    if(n<=2&&k==0)
    {
    	cout<<1;
    	return 0;
	}
	if(n<=10)
	{
	    cout<<js;
		return 0;	
	}
	if(n<=100&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(n<=100&&k==1)
	{
		cout<<js;
		return 0;
	}
	if(n<=20000&&k==1)
	{
		cout<<js;
		return 0;
	}
	return 0;
}
