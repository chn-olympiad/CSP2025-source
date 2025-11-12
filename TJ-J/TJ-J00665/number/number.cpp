#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	int l;
	l=strlen(s);
	for(int i=0;i<l;i++)	cin>>s[i];
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
