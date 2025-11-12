#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n=s.length();
	int p=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) 
		{
			if(s[i]>s[j])
			{
				swap(s[i],s[j]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]>'9'||s[i]<'0')
		{
			continue;
		}
		else
		{
			a[p]=s[i]-'0';
			p++;
		}
	}
	for(int i=1;i<p;i++)
	{
		cout << a[i];
	}
	return 0;
}
