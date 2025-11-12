#include<bits/stdc++.h>
using namespace std;
string st;
int ans,c[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>st;
	int len=st.size();
	for(int i=0;i<st.size();i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		{
			c[st[i]-'0']++;
		}
	}
	sort(c+1,c+ans+1);
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=c[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}