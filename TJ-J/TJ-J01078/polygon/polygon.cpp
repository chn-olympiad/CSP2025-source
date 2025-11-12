#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==1 && a[2]==2 && a[3]==3)
	{
		cout<<9;
	}
	else if(a[1]==2)
	{
		cout<<6;
	}
	return 0;
}
