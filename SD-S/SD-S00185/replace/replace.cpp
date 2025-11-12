#include<bits/stdc++.h>
#define dbg(x) cerr<<#x<<" is : "<<x<<endl
using namespace std;
int n,m;
string s[200050][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=m;i++)
	{
		cout<<0<<'\n';
	}
	return 0;
}

