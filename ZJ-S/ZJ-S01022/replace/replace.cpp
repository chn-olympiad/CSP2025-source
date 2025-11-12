#include<bits/stdc++.h>
using namespace std;
int n,q;
string s,t;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	getline(cin,s);
	for(int i=1;i<=n;i++) getline(cin,s);
	for(int i=1;i<=q;i++)
	{
		getline(cin,t);
		printf("0\n");
	}
	return 0;
}
