#include<bits/stdc++.h>
using namespace std;
long long a[15];
string x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,x);
	for(long long i=0;i<=x.size()-1;i++)
	{
		if('0'<=x[i] && x[i]<='9')
		{
			a[x[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]--)
		{
			printf("%d",i);
		}
	}
	return 0;
}
