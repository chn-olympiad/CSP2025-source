#include <bits/stdc++.h>
using namespace std;
string s;
int sum,a[11]={};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		char d=s[i];
		if(d-'0'>=0&&d-'0'<=9)
		{
			a[d-'0']++;
		}
	}
	sum=10;
	for(int i=1;i<=10;i++)
	{
		sum--;
		for(int j=1;j<=a[sum];j++)
		{
			cout<<sum;
		}
	}
	return 0;
}
