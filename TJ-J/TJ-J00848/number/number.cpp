#include <bits/stdc++.h> 
using namespace std;
string s,b;
long long a[100005];
bool cmp(int c,int d)
{
	return c>d;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='0')
		{
			b+=s[i];
		}
	}
	sort(b.begin(),b.end(),cmp);
	cout << b;
	return 0;
}
