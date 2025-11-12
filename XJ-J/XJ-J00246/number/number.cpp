#include<bits/stdc++.h>
using namespace std;
int m[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int num=0;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		m[++num]=s[i]-'0';
	}
	sort(m+1,m+1+num);
	for(int i=num;i>=1;i--)
	cout<<m[i];
	return 0;
 } 
