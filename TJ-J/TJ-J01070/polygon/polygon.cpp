#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	cout<<ans/2-1;
	return 0;
}
