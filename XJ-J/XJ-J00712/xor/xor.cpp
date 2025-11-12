#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()

{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		if(a[i]<=m)
		{
			cout<<a[i];
				return 0;
		}
	}
	return 0;
}
