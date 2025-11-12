#include<bits/stdc++.h>
using namespace std;
char c;
string s;
long long i=1,d[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;;i++)
	{
		c=s[i];
		if(c-'0'<=9&&c-'0'>=0)
			d[c-'0']++;
		else if(c<'a'||c>'z')
			break;
	}
	for(int j=9;j>=0;j--)
		for(int k=1;k<=d[j];k++)
			cout<<j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
