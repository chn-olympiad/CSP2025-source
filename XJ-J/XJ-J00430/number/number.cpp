#include<bits/stdc++.h>
using namespace std;
char a;
int t[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a)
	{
		if(a>='0'&&a<='9') t[a-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=t[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
