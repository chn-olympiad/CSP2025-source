#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
char a[N];
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int top = 0;
	cin>>s;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[++top] = s[i];
		}
	}
	sort(a+1,a+1+top,cmp);
	for(int i = 1;i<=top;i++)
	{
		cout<<a[i];
	}
	return 0;
}

