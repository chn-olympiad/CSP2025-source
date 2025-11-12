#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l;
	string s;
	cin>>s;
	l=s.size();
	for(int i=1;i<=1000005;i++)
	{
		a[i]=-1;
	}
	for(int i=0;i<l;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[i]=s[i]-'0';
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--)
	{
		if(a[i]!=-1)
		{
			cout<<a[i];
		}
	}
	return 0;
}
 
