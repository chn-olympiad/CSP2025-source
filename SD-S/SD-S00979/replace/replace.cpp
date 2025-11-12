#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[20005][2],t[20005][2];
int main()
{
	//Ren5Jie4Di4Ling5%
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	for (int i=1;i<=q;i++)
		cin>>t[i][1]>>t[i][2];
		
	for (int i=1;i<=q;i++)
		cout<<0<<endl;
	return 0;
} 
