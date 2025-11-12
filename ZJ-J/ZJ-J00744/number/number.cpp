#include<bits/stdc++.h>
using namespace std;
string s;
int b[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s)
		if(isdigit(c))
			b[c-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=b[i];j++)
			cout<<i;
}