#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	cin>>s;
	char ch='9';
	for (;ch>='0';ch--)
	{
		for (const auto&i:s)
		{
			if (i==ch)
			{
				ans+=ch;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}