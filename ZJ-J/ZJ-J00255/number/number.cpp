#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
char num[1000005];
int cnt=0;
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt++;
			num[cnt]=s[i];
		}
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<num[i];
	}
	return 0;
}