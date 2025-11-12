#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100000]={};
	long long t=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		char n=s[i];
		if(n<='9'&&n>='0')
		{
			a[t]=n-'0';
			t++;
		}
	}
	sort(a,a+t);
	
	for(int i=t-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
