#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[1100],x,y;
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i=k)
		{
			continue;
		}
		cout<<a[i];
	}
	return 0;
}
