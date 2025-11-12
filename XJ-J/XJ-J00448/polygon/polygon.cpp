#include <bits/stdc++.h>
using namespace std;
int n,a[1005],sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	cout <<sum; 
	return 0;
}
