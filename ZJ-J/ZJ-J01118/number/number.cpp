#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	int b[11]={},n=0;
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]<='9'&&s[i]>='0') 
		{
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(b[i]>0)
		{
			b[i]--;
			cout<<i;
		}
	}
	return 0;
}
