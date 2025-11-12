#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long c[1001];
	long long b=0;
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]==48||s[i]==49||s[i]==50||s[i]==51||s[i]==52||s[i]==53||s[i]==54||s[i]==55||s[i]==56||s[i]==57)
		{
			c[b]=s[i]-48;
			b++;
		}
	}
	sort(c,c+b);
	for(long long i=b-1;i>=0;i--)
	{
		cout<<c[i];
	}
	return 0;
}