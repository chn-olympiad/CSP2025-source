#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length();
	char a[1000001];
	int b[1000001]={},n=0;
	for(int i=0;i<l;i++) a[i]=s[i];
	for(int i=0;i<l;i++)
	{
		if(a[i]>='1'&&a[i]<='0')
		{
			b[i]=a[i]-'0';
			n+=1;
		}
	}
	for(int i=0;i<=n;i++)
	{
		int ma=0;
		for(int j=0;j<=i+1;j++)
		{
			ma=max(b[j],ma);
		}
		cout<<ma;
	}
	return 0;
}
