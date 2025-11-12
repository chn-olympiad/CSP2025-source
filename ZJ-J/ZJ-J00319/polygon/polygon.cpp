#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,max=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(max<a[i])
			max=a[i];
	}
	sort(a+1,a+n+1);
	if(max==1)
	{
		cout<<n-2;
		return 0;
	}	
	if(a[1]+a[2]>a[3])
		cout<<1;
	else
		cout<<0;
	return 0;
}

