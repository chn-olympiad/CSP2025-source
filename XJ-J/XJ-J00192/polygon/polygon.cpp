#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0,num=0;
	cin>>n;
	int a[5005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num+=a[i];
	}
	ans=num/3-2;
	cout<<ans;
	return 0;
}
