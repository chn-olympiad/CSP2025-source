#include<bits/stdc++.h>
using namespace std;
char s[1000005];
long long a[1000005],m=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			m++;
			a[m]=s[i]-'0';
		}
	}
	sort(a+1,a+m+1);
	bool f=false;
	for(int i=m;i>=1;i--)
	{
		if(a[i]!=0)
		{
			cout<<a[i];
			f=true;
		}
		else
		{
			if(f==true)
			cout<<a[i];
			else if(i==1)
			cout<<0;
		}
	}
	return 0;
}