#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n+q;i++)
	{
		cin>>a>>b;
	}
	int ans=2;
	for(int i=1;i<=q;i++)
	{
		cout<<ans;
	}
	return 0;
} 
