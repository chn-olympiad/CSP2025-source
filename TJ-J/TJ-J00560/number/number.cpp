#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	getline(cin,s);
	int len=s.size();
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]<='9'&&s[i]>='0') a[cnt++]=s[i];
	}
	sort(a,a+cnt,cmp);
	if(a[0]=='0') cout<<0;
	else
	{
		for(int i=0;i<cnt;i++) cout<<a[i];
	}
	return 0;
}
//mycode
