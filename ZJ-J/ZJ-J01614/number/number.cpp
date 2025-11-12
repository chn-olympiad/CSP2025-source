#include<bits/stdc++.h>
using namespace std;
int num[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int j=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[j]=int(s[i]-'0');
			j++;
		}
	}
	sort(num,num+j);
	for(int i=j-1;i>=0;i--)
	{
		cout<<num[i];
	}
	return 0;
}
//hajimi nanbeilvdou
//feropen(致敬我的同学，他去年因此爆0，默哀)
//freopen("nihao.in","r",stdin);
//freopen("zaijian.out","w",stdout);
//
