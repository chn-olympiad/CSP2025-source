#include<iostream>
using namespace std;
string s;
int f,c[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')	c[s[i]-'0']++;
	}
	for(int i=9;i>0;i--)
	{
		if(c[i]!=0)		f=1;
	}
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	else
	{
		for(int i=9;i>=0;i--)
		{
			for(int j=c[i];j>0;j--)		cout<<i;
		}
	}
	return 0;
}
