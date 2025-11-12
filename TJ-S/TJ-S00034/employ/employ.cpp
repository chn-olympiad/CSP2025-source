#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	for(int i = 1;i <= n;i++)
	{
		if(s[i]=='1')
		{
			ans++;
		}
	}
	cout<< ans;
	return 0;
}
