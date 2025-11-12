#include <bits/stdc++.h> #SN-J00101
using namespace std;
int n,a[5005],ans=0;
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
		int num;
		int b[5005];
		int k=i;
		for(int j=1;j<=k;j++)
		{
			num+=a[j];
			b[i]=a[j];
		}
		if(num>a[n]*2)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
