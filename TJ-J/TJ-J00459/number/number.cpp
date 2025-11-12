#include <bits/stdc++.h>
using namespace std;
int cnt[15];
char s[1000006];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for (int i=0;i<n;i++)
	{
		if (s[i]=='0')
		{
			cnt[0]++;
		}
		else if (s[i]=='1')
		{
			cnt[1]++;
		}
		else if (s[i]=='2')
		{
			cnt[2]++;
		}
		else if (s[i]=='3')
		{
			cnt[3]++;
		}
		else if (s[i]=='4')
		{
			cnt[4]++;
		}
		else if (s[i]=='5')
		{
			cnt[5]++;
		}
		else if (s[i]=='6')
		{
			cnt[6]++;
		}
		else if (s[i]=='7')
		{
			cnt[7]++;
		}
		else if (s[i]=='8')
		{
			cnt[8]++;
		}
		else if (s[i]=='9')
		{
			cnt[9]++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		while (cnt[i])
		{
			cout<<i;
			cnt[i]--;
		}
	}
	return 0;
 } 
