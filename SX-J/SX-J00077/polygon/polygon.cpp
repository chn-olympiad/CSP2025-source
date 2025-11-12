#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n<=2)cout<<0;
	else
	{
		if(max(a[2],max(a[0],a[1]))*2<a[0]+a[1]+a[2])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
}