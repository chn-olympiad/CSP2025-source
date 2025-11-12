/*
SN-J00929
董国栋
西安市曲江第一学校 
*/
#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[1000010];
bool cmp(int a1,int a2)
{
	return a1>a2; 
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			a[++n]=s[i]-'0';
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		cout<<a[i];
	return 0;
}
