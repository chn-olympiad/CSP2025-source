#include<bits/stdc++.h>
using namespace std;
string st;
int b[101];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>st;
	int l=st.size();
	for(int i=0;i<l;i++)
	{
		if('0'<=st[i]&&st[i]<='9')
		{
			b[st[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=b[i];j++)
		{
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
