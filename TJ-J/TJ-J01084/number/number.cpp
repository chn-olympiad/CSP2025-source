#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
string s;
string str = "";
long long sum;
long long a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long j = 0;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[++j] = int(s[i]-'0');
		}
	}
	sort(a+1,a+j+1);
	for(int i = j;i>=1;i--)
	{
		str += char(a[i]+'0');
	}
	cout<<str;
	return 0;
}
