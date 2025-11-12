#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[100],k=1;
	string s;
	cin>>s;
	for(int i=1;i<=s.lenghe();i++)
	{
		if(s[i]>='1' && s[i]<='9')
		{
			a[k]=s[i];
			k++;
		}
	}
	k-=1;
	for(int i=1;i<=k;i++)
	{
		if(a[i]<a[i+1])
		{
			int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cout<<a[i];
	}
	return 0;
}
