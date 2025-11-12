#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000010];
int len;
int p;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.length();
	for(int i=0;i<len;++i)
	{
		if((s[i] - '0')>=0&&(s[i] - '0')<=9)
		{
			a[++p] = (s[i] - '0');
		}
	}
	sort(a+1,a+1+p,cmp);
	for(int i=1;i<=p;++i)
	{
		cout << a[i];
	}
	return 0;
}
