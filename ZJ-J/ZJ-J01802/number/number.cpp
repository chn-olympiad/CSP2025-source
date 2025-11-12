#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		a[s[i]]++;
	for(int i='9';i>='0';i--)
		for(int j=1;j<=a[i];j++)
			printf("%c",i);
	return 0;
}