#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string p="";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			p+=s[i];
		}
	}
	sort(p.rbegin(),p.rend());
	for(int i=0;i<p.size();i++)
	{
		cout<<p[i];
	}
}
