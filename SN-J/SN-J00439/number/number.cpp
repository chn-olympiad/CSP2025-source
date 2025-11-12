#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int p=1;
	for(int i=0;i<s.size();i++)
	{
		int n=s[i];
		if(n>=48&&n<=57)
		{
			a[p]=s[i]-'0';
			p++;
		}
	}
	p--;
	sort(a+1,a+p+1);
	for(int i=p;i>=1;i--)
	{
		cout << a[i];
	}
	return 0;
}
