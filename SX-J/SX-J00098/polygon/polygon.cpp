#include <bits/stdc++.h>
using namespace std;
long long n,k,a[5005],h;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		h+=i;
		h+=i*(i+1);
	}
	cout<<h;
	return 0;
}