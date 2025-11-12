#include<bits/stdc++.h>
using namespace std;
string s,s1;
int a[101010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a[t]=s[i]-'0';
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
