#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
	}
	cout<<x%998244353;
	return 0;
}
