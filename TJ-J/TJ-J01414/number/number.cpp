#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a1,int a2)
{
	return a1>a2;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int flag=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[flag]=int(s[i]-48);
			flag++;
		}
	}
	sort(a,a+flag,cmp);
	string b;
	for(int i=0;i<flag;i++)
	{
		b+=char(a[i]+48);
	}
	cout<<b;
	return 0;
}
