#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000100],sum;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main( )
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++sum]=s[i]-'0';
		}
	}
	sort(a+1,a+1+sum,cmp);
	for(int i=1;i<=sum;i++)
	{
		cout<<a[i];
	}
	return 0;
}
//I LOVE BYM
//QwQ
