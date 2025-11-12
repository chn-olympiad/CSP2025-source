#include<bits/stdc++.h>
using namespace std;
string str;
int n,a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>='0'&&str[i]<='9')	a[n++]=str[i]-'0';		
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}