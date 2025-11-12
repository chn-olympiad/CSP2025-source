#include<bits/stdc++.h>
using namespace std;
string a;
int cnt = 0;
char s[10000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i = 0;i < a.size();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			s[++cnt] = a[i];
		}
	}
	sort(s+1,s+1+cnt);
	for(int i = cnt;i > 0;i--)
	{
		cout<<s[i];
	}
	return 0;
}
