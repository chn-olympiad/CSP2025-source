#include<bits/stdc++.h>
using namespace std;
string s;
int a[1001],o;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=sizeof(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[o]=s[i]-'0';
			o++;
		}
	}
	sort(a,a+o);
	for(int i=o-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
