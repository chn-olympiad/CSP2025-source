#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3)
	{
		cout<<0;
	}
	else if(n==3)
	{
		int maxa=max(a[1],a[2]);
		maxa=max(maxa,a[3]);
		int sum=a[1]+a[2]+a[3];
		if(sum>maxa*2)cout<<1;
		else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
