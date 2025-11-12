#include<bits/stdc++.h>
using namespace std;
string s;
int a[20],len=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	while(s[len])
	{
		if(s[len]>='0' && s[len]<='9')
		{
			a[s[len]-'0']++;
		}
		len++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			printf("%d",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
