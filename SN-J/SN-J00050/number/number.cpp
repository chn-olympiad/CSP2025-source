#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
string s,d;
long long a[N],cnt;
bool cmp(long long x,long long y)
{
	return x > y; 
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(long long i = 0;i < s.size();i++)
	{
		if(s[i] - '0' == 0 || s[i] - '0' == 1 || s[i] - '0' == 2 || s[i] - '0' == 3 || s[i] - '0' == 4 || s[i] - '0' == 5 || s[i] - '0' == 6 || s[i] - '0' == 7 || s[i] - '0' == 8 || s[i] - '0' == 9) d += s[i];
	}
	cnt = d.size();
	for(long long i = 0;i < d.size();i++)
	{
		a[i + 1] = d[i] - '0';
	}
	sort(a + 1,a + cnt + 1,cmp);
	for(long long i = 1;i <= cnt;i++) cout << a[i];
	return 0;
}
