#include <bits/stdc++.h>
using namespace std;
long long int ai=0,s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b;
	int f=0;
	cin>>a;
	int l=a.size();
	for (int i=0;i<l;i++)
	{
		if(int(a[i])>=48 && int(a[i])<=57)
		{
			ai++;
			s[ai]=int(a[i])-48;
		}
	}
	sort(s+1,s+ai+1);
	for (int i=ai;i>=1;i--)
	{
		cout<<s[i];
	}
	return 0;
} 
