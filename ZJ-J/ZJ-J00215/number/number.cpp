#include<bits/stdc++.h>
using namespace std;
char s[10000010];
int n,a[1000010],f,t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ls=strlen(s);
	for(int i=0;i<ls;i++)
	{
		if('0'<=s[i]&&s[i]<='9') a[++n]=s[i]-'0';
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		if(a[i]==0&&t==0) continue;
		else
		{
			t=1;
			cout<<a[i];
			f=1;
		}
	}
	if(f==0) cout<<0;
	return 0;
}