#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],b[1000005];
long long ii=0,sum0=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			a[ii]=s[i]-'0';
			ii++;
		}
	}
	sort(a,a+ii);
	for(long long i=ii-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
