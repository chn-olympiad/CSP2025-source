#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,f=1,ss=1,sum=0;
	string s;
	cin>>n>>m;

	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]=='1')sum++;
		if(s[i]=='0')f=0;
	}
	if(m==n&&f==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=sum;i++)
	{
		ss=ss*i%998244353;
	}
	cout<<ss;



	return 0;
}