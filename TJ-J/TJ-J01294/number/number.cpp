#include <iostream>
#include <cstdio>
using namespace std;
char ch[10000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	s+=' ';
	int n = 0;
	scanf("%c",&ch[n]);
	while(ch[n]!='\n')
	{
		s+=ch[n];
		scanf("%c",&ch[++n]);
	}
	string ans;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans+=s[i];
		}
	}
	string box[19] = {};
	for(int i=0;i<ans.size();i++)
	{
		box[ans[i]-'0']+=ans[i];
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<box[i].size();j++)
		{
			printf("%c",box[i][j]);
		}
	}
	return 0;
}
