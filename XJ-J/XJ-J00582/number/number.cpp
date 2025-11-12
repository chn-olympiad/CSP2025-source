#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long j=0;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(long long i=0;i<j;i++)
	{
		cout<<a[i];
	}
	return 0;
}
