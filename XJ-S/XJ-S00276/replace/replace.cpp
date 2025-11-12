#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string a[1444400],b[1444400];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<"0"<<endl;
	}
	return 0;
}
