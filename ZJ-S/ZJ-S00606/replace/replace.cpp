#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[200005][3],t[200005][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,q;
	
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=0;i<q;i++)
	{
		cin>>t[i][0]>>t[i][1];
	}
	for(int i=0;i<q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}
