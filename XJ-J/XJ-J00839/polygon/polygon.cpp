#include<bits/stdc++.h>
using namespace std;	
long long int i,j,a[1000008],b,n;
int main()
{

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2)
	cout<<0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		return 0;
	}
	cout<<n-2;
	return 0;
}
