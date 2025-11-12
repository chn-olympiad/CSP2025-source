#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[105];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
	if(sum>a[n-1]*2)
	{
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}