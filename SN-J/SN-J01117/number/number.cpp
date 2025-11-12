#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005ll];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size();
	long long j=0;
	for(long long i=0;i<n;i++)
	{
		if('0'<=s[i] and '9'>=s[i])
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j+1);
	for(long long i=j;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}


