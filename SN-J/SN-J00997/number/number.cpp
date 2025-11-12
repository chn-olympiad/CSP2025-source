#include<bits/stdc++.h>
using namespace std;
int len=0,a[1000010],ret=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++ret]=(int)s[i]-48;
		}
	}
	sort(a+1,a+1+ret);
	for(int i=ret;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
