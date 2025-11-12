#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,a[5005],mixn,k,s,r,m,v[5005],x;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
		if(a[i]>mixn)
		mixn=a[i];
	}
    if(s>mixn*2)
    {
    	cout<<1;
	}
    else
    {
    	cout<<0;
	}
	return 0;
}

