#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),m=0;
	for(int i=0;i<l;i++)
	{
       if(s[i]>='0'&&s[i]<='9')
	   {
	     m++;
	    a[m]=s[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[j]<a[j+1])
			{
				int x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
       cout<<a[i]-48;
	}
	return 0;
}