#include<bits/stdc++.h>
using namespace std;
long long n,k,h=1,hh=1,a[500010],f[3],ans,used[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) h=0;
		if(a[i]==0||a[i]==1) f[a[i]]++;
		if(a[i]!=0&&a[i]!=1) hh=0;
	}
	if(hh&&k==1)
	{
		cout<<f[1];
		return 0;
	}
	if(hh&&k==0)
	{
		for(int i=1;i<=n;i++) 
		{
			if(a[i]==1&&a[i-1]==1) 
			{
				ans++;
				i++;
			}
		}
		cout<<ans+f[0];
		return 0;
	}
	return 0;
}