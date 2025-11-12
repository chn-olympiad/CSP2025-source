#include <bits/stdc++.h>
using namespace std;
bool cmp(char x,char y)
{
	return x-'0'>y-'0';
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[1000005];
	int to_a=1;
	for(int i=0;i<=s.length();i++)
	{
		if(s[i]-'0'>=0 && s[i]-'0'<=9)
		{
			a[to_a]=s[i];to_a++;
		}
	}
	sort(a+1,a+to_a+1,cmp);
	for(int i=1;i<=to_a;i++)
	{
		cout<<a[i];
	}
	return 0;
}
