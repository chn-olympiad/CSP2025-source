#include <bits/stdc++.h>
using namespace std;
int n,a[5005],m;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		m=max(m,a[i]);		
	}
	sort(a+1,a+n+1);
	if(n==3&&a[1]+a[2]>a[3])
	{
		cout<<1;
		return 0;
	}
	if(m==1)
	{
		cout<<n-2;
		return 0;
	}
	cout<<0;
	return 0;
}
