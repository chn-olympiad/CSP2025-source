#include<bits/stdc++.h>
using namespace std;
string s;//9  57
long long a[15];
int main()//0  48
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size();
	for(long long i=0;i<n;i++)
	{
		if(48<=s[i]&&s[i]<=57)
			a[s[i]-48]++;
	}
	for(long long i=9;i>=0;i--)
	{
		for(long long j=1;j<=a[i];j++)
			cout<<i;
	}
	return 0;
}