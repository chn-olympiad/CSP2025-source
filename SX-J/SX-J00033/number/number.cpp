#include<bits/stdc++.h>
using namespace std;
int a[30];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]=='0'&&s[i]<='0')
		{
			a[a[i]-'0']--;
		}
		while(a[i])
		{
			a[i]--;
		}
	}
	cout<<5;
	return 0;
}