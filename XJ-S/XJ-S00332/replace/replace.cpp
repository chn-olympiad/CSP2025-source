#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,q;
string s[N][10],t[N][10];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
		cout<<"0\n";
	}
	return 0;
}
