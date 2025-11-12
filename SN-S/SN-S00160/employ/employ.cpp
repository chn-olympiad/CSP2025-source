#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n1,n,m,ans=1;
	cin>>n1>>m;
	n=n1;
	string s;
	cin>>s;
	for(int i=1;i<=n1;i++)
	{
		int a;
		cin>>a;
		if(a==0) n--;
	}
	if(n>m){
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			if(ans>=998244353)ans%=998244353;
		}
		cout<<ans%998244353;
	}
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
