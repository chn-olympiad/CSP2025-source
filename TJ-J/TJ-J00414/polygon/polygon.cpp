#include<bits/stdc++.h>
using namespace std;
int a[5009],n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	} 
	cout<<a[n];
	return 0;
}
