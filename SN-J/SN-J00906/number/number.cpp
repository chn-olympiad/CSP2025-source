#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],bb;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	int l1=l;
	for(int i=0;i<l;i++)
	{
		if(s[i]>=48&&s[i]<=58)
		{
			a[bb]=s[i]-48;
			bb++;
		}
		else
		{
			l1--;
		}
	}
	sort(a,a+l1,cmp);
	for(int i=0;i<l1;i++)
	{
		cout<<a[i];
	}
	return 0;
}
