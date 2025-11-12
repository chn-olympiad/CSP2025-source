#include<bits/stdc++.h>
using namespace std;
int ans[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			ans[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=ans[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
