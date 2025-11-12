#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100001],s1=0,s2=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++s1]=s[i]-'0';
		}
	}
	sort(a+1,a+s1+1);
	for(int i=s1;i>=1;i--)
	{
		s2=s2*10+a[i];
	}
	cout<<s2;
	return 0;
}
