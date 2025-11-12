#include <bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for (int i=0;i<n;i++)
	{
		int cur=s[i]-'0';
		if (cur>=0 && cur<=9)a[cur]++;
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=a[i];j++)cout<<i;
	}
	return 0;
}
