#include <bits/stdc++.h>
using namespace std;
string s;
int t[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=0;i<s.length();i++)
		if(s[i]>='0'&&s[i]<='9')
			t[s[i]-'0']++;
	bool f=0;
	for(int i=1;i<9;i++)
		if(t[i])
			f=1;
	if(f)
	{
		for(int i=9;~i;i--)
			for(int j=0;j<t[i];j++)
				cout<<i;
	}
	else cout<<0;
	return 0;
}
