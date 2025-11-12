#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s[10001][2]={},a,b;
	cin>>n>>q;
	for(int i = 1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for(int i = 1;i<=q;i++)
	{
		cin>>a>>b;
		cout<<a.length()+b.length()-i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
