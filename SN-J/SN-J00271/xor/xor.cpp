#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
