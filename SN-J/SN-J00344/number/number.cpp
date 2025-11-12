#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],l=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<48 || s[i]>57)
		{
			continue;
		}
		a[l]=s[i]-48;
		l++;
	}
	l--;
	sort(a+1,a+l+1);
	for(int i=l;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
