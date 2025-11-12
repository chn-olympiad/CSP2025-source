#include<bits/stdc++.h>
#define ll long long
#define db double
const int N=1e6+10;
using namespace std;
string s;
ll vis[110];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			vis[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=vis[i];j++)
			cout<<i;
	return 0;
}
