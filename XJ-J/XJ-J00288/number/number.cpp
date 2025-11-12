#include <bits/stdc++.h>
using namespace std;
string s;
int p=0,b=0;
char a[100010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			p++;
			a[p]=s[i];
		}
	}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<p;j++)
		{
			if(a[j]<a[j+1])
			{
				char num=a[j];
				a[j]=a[j+1];
				a[j+1]=num;
			}
		}
	}
	for(int i=0;i<p;i++)
	{
		cout<<a[i];
	}
	return 0;
}
