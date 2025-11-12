#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t="";
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t+=s[i];
		}
	}
	sort(t.begin(),t.end(),cmp);
	cout<<t;
	return 0;
}
