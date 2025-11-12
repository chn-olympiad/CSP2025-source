#include<bits/stdc++.h>
//OK
using namespace std;
int cnt[2000];
string s;
int main()
{
	freopen("number.in","r",stdin);//jidegai 
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			cnt[(int)(s[i]-'0')]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			printf("%d",i);
		}
	}
	return 0;
 } 
