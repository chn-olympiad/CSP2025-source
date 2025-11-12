#include <bits/stdc++.h>
using namespace std;
string s,num;
int a[15],w;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		w=s[i]-'0';
		if(w>=10) continue;
		else
		{
			a[w]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			num+=i+'0';
			
		}
	}
	cout << num;
	return 0;
}
