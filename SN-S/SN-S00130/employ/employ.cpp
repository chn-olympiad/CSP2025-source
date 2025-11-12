#include <bits/stdc++.h>
using namespace std;
int a[700];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long ans=1;
	cin>>n>>m;
	string s;
	cin>>s;
	int q=0,w=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			n--;q++;
			a[i]=600;	
		}
	}
	for(int i=1;;i++)
	{	w=q;
		for(int j=1;j<=n;j++)
		{
			if(a[i]<=q)
			{
				n--;q++;
			}
		}
		if(w==q)
		{
			break;
		}
	}
	if(n<m)
	{
		cout<<"0";
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		ans=(ans*i+998244353)%998244353;
	}

	
	cout<<ans;
	return 0;
}
