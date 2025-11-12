#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000001], cnt=0, n;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	n=s.size();
	for(long long i=0;i<n;i++)
	{
		if(isdigit(s[i]))
		{
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(a, a+n, greater<long long>());
	for(long long i=0;i<cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
