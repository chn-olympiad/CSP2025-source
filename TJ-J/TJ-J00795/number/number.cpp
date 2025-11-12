#include<bits/stdc++.h>
using namespace std;
int h[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string st;
	cin>>st;
	for(int i = 0;i < st.size();i++)
	{
		if('0' <= st[i] && st[i] <= '9')
		{
			h[st[i] - '0']++;
		}
	}
	for(int i = 9;i >= 0;i--)
	{
		for(int j = 1;j <= h[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
