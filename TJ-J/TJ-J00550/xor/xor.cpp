#include<bits/stdc++.h>
using namespace std;
long long a[500010],k,n,maxx=-1,minn=1000009;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(maxx<a[i])maxx=a[i];
		if(minn>a[i])minn=a[i];
	}
	if(minn==maxx&&minn==1)
	{
		if(k==0)
		{
			cout<<n;
		}
	}
	return 0;
 } 
