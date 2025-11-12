#include<bits/stdc++.h>
using namespace std;
int a[10]={};
string s,h;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]>0)
		{
			char c=(i+'0');
			for(int j=0;j<a[i];j++)
			{
				h+=c;
			}
		}
	}
	cout<<h;
	return 0;
}
