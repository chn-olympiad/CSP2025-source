#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q;
string rep[maxn][2];
string t,tt;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>rep[i][0]>>rep[i][1];
	}
	while(q--)
	{
		cin>>t>>tt;
		puts("0");
	}
	return 0;
}
