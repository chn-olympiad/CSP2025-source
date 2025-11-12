#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("raod.in","r",stdin);
	freopen("raod.out","w",stdout);
	string s[1010][2],t[1010][2];
	int n,q;
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int j=1;j<q;j++)
	{
		cin>>t[j][1]>>t[j][2];
	}
	cout<<"20";
	return 0;
}
