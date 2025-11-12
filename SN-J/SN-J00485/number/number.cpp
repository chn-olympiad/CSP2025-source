#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000];
int m=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			m++;
			a[m]=s[i]-48;
			
		}
	}
	sort(a+1,a+m+1);
	for(int i=m;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
