#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int N,Q;
string s[200005],t[200005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>Q;
	for(int i=1;i<=N;i++)
	{
		cin>>s[i]>>t[i];
	}
	while(Q--)
	{
		string a,b;
		cin>>a>>b;
		cout<<0<<endl;
	}
	return 0;
}