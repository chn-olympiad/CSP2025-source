#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100005],ans,aa;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			aa++;
		}
	}
	if(aa==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

