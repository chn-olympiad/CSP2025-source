#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cnt;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int siz = (int)s.size();
	s = ' ' + s;
	for(int i = 1; i <= siz; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[++cnt] = (int)(s[i] - '0');
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i = 1; i <= cnt; i++) cout << a[i];
	return 0;
}
