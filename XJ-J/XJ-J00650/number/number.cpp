#include<bits/stdc++.h>
using namespace std;
char s[1000005];
long long int a[15]={0};
int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	int l,x=9;

	cin>>s;
	l=strlen(s);
	for(int i=0;i<=l-1;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a[s[i]-'0']++;
		}
	}
	while(x>-1)
	{
		for(int i=1;i<=a[x];i++)
		{
			cout<<x;
		}
		x--;
	}
	return 0;
}
