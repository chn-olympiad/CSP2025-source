#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(n==1 and (s[i]>='0' and s[i]<='9'))
		{
			cout<<s[i];
			return 0;
		}
		else if(s[i]>=0 and s[i]<=9)
		{
			a[i]=s[i];
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
