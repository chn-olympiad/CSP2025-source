#include <bits/stdc++.h>
using namespace std;
const int N=1e6+6;
char str[N];
int n;
int t[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			t[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=t[i];j>=1;j--)
		{
			cout<<i;
		}
	}
	cout<<'\n';
	return 0;
}
