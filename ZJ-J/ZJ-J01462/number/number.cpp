#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e6+5;
string s;
int t[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	s=' '+s;
	int i=1;
	while(s[i])
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t[s[i]-'0']++;
		}
		i++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=t[i];j++) cout<<i;
	}
	return 0;
}
