#include<bits/stdc++.h>
using namespace std;
string s;
int z[12]={};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			z[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(z[i]!=0)
		{
			z[i]--;
			printf("%d",i);
			
		}
	}
	printf("\n");
	return 0;
}
