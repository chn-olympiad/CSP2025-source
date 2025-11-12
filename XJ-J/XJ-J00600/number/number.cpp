#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],top;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a[top++]=s[i]-'0';
		} 
	}
	sort(a,a+top);
	reverse(a,a+top);
	for (int i=0;i<top;i++)
		printf("%d",a[i]);
	return 0;
} 
