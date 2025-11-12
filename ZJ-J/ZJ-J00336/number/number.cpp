#include<bits/stdc++.h>
using namespace std;
int i,j,len,a[1000005],n=0;
char s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	len=0;
	s[len]='1';
	while((s[len]-'0'>=0&&s[len]-'0'<=9)||(s[len]-'a'>=0&&s[len]-'a'<=26))
	{
		len++;
		s[len]=getchar();
	}
	for(i=1;i<=len;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	for(i=n;i>=1;i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
