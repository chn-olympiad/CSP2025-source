#include<bits/stdc++.h>
using namespace std;
int a[2000010],n=0,ans=0,t=0;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--)
	{
		if(a[i]!=0||t)
		{
			cout<<a[i];
			t=1;
		}
	}
	cout<<a[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
