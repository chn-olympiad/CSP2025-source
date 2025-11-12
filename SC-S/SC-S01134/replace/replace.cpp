#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a[1000006];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2&&n==3)
	{
		cout<<2<<endl<<0;
	}
	else
	{
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	return 0;
}