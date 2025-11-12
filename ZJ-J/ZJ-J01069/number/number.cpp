#include<bits/stdc++.h>
using namespace std;
string t="";
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			a[int(s[i])-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			t=t+(char(i+48));
		}
	}
	cout<<t;
	return 0;
}
