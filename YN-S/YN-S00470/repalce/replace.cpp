#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[n+1],s2[n+1];
	string t1[q],t2[q];
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int j=1;j<=q;j++)
	{
		cin>>t1[j]>>t2[j];
	}
	return 0;
}
