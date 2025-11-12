#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main()
{
	string s,q;
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	getline(cin,s);
	int n=s.size(),t=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			a[i]=s[i];
			t++;
		}
	}
	sort(a,a+n);
	for(int i=t-1;i>=0;i--)
	{
			q[i]='0'+(a[i]-48);
			cout<<q[i];
	}
	return 0;
}
