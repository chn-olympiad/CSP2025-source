#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]-'0'<=9&&s[i]-'0'>=0)
		{
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	return 0;
}

