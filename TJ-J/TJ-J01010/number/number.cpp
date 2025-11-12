#include <bits/stdc++.h>
using namespace std;
long long a[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int a1=int(s[i]-'0');
			a[a1]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0)
		{
			while(a[i]>0)
			{
				cout << i;
				a[i]--;
			}
		}
	}
	return 0;
 } 
