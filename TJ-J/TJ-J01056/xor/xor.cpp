#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n,k;
long long ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
			ans++;
	}
	if(k==0)
	{
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		for(int l=1,r=i;r<=n;l++,r++)
		{
			int temp=0;
			for(int j=0;j<i;j++)
				temp^=a[l+j];
			if(temp==k)
				ans++;
		}
	}
	cout<<ans;
	return 0;
}
