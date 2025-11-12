#include <bits/stdc++.h>
using namespace std;
long long n,m,con;
string s;
long long num=1;
long long c[501];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(long long i=0;i<n;i++)
	{
		cin>>c[i];
	}
	for(long long i=0;i<s.length();i++)
	{
		if(s[i]=='1')
		{
			con++;
		}
	}
	
	if(con==s.length())
	{
		for(int i=1;i<=n;i++)
		{
			num*=i;
		}
		cout<<num%998244353;
	}
	
	else if(m==n)
	{
		sort(c,c+n);
		if(c[n-1]<s.length()-con)
			cout<<"0";
	}
	
	return 0;
}
