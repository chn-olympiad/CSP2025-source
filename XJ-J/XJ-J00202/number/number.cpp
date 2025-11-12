#include <bits/stdc++.h>
using namespace std;
long long int a,b[1000005],k,i;
char s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=strlen(s);
	for(i=0;i<=a;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			b[k++]=s[i]-'0'; 
		}
	}
	sort(b,b+k);
	for(i=k-1;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
