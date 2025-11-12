#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length(),sum=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+n);
	for(int i=0;i<sum;i++)
	{
		b[i]=a[n-i-1];
		cout<<b[i];
	}
	return 0;
}
