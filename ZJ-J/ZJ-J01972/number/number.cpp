#include<bits/stdc++.h>
using namespace std;
int vis[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen("number4.in","r",stdin);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
//	cout<<s.size()<<endl;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			vis[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(vis[i]--)
		{
			cout<<i;
		}
	}
	return 0;
}
