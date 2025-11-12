#include<bits/stdc++.h>
//#define int long long
//#define pqg priority_queue<int,vector<int>,greater>
//#define pql priority_queue<int,vector<int> >
using namespace std;
string s;
int b[20];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')b[s[i]-'0']++;
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=b[i];j++)cout<<i;
	}
	return 0;
}
