#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
long long maxx=-1000000;
long long a[10000005],b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0' || s[i]=='1' || s[i]=='2'|| s[i]=='3'|| s[i]=='4'|| s[i]=='5'|| s[i]=='6'|| s[i]=='7'|| s[i]=='8'|| s[i]=='9')
		{
			a[i]=s[i]-48;
		}
		else
		{
			a[i]=a[i-1];
		}
	}
	for(int j=0;j<s.size();j++)
	{
		if(a[j]>maxx)
		{
			maxx=a[j];
			b[j]=a[j];
		}
	}
	cout<<maxx;
	return 0;
}
