#include <bits/stdc++.h>
using namespace std;
int a[15]={0};
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	
	
	for(long long i = 0;i < s.length();i++)
	{
		if((int(s[i])-48)>=0&&(int(s[i])-48)<=9)
		{
			a[int(s[i])-48]+=1;
		}
		
	}
	for(long long i = 9;i >= 0;i--)
	{
		for(long long j = 1;j <= a[i];j++)
		{
			cout << i;
		}
	}
	return 0;
}
