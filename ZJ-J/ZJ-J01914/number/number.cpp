#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int cnt;
int mp[10];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i]!='\0';++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			++mp[s[i]-'0'];
		}
	}
	for(int i=9;i>=0;--i)
	{
		for(int j=1;j<=mp[i];++j)
		{
			putchar(i+'0');
		}
	}
	return 0;
}

