#include <bits/stdc++.h> 
using namespace std;
int num,a[1000005],cnt;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int cnt=0;
	for(int i=0;i<s.length();i++)
	{
		if((s[i]>='0')&&(s[i]<='9'))
		{
			cnt++;
			a[cnt]=s[i]-48;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		sort(a+1,a+cnt+1);
	}
	for(int i=cnt;i>=1;i--)
	{
		cout << a[i];
	}
	return 0;
}
