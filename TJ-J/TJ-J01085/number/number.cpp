#include <bits/stdc++.h>
using namespace std;
char s[1000010];
void Extract(char *s)
{
	int len=strlen(s);
	sort(s,s+len);
	int t=0;
	for(int i=len-1; i>=0; --i)
	{
		if(s[i]>='0' && s[i]<='9') cout<<s[i];
		else continue;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s); 
	Extract(s);
	return 0;
}
