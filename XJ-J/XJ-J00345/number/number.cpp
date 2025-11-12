#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n=0,a[1000000];
	cin>>s;
	for(int i=0;i<sizeof(s);i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[n]=s[i]-'0';
			n++;
		}
	}
	for(int i=0;i<n;i++)
	{
		int c=i;
		for(int j=i;j<n;j++)
		{
			if(a[j]>a[c])
			{
				c=j;
			}
		}
		swap(a[i],a[c]);
	}
	for(int i=0;i<=(n-1)/2;i++)
	{
		swap(a[i],a[n-i+1]);
	}
	cout<<a;
	return 0;
}
