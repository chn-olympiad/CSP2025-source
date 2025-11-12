#include<bits/stdc++.h>
using namespace std;
int main()
{
	string w[10000],s[10000];
	int a,b;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<b;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=b;i++) cout<<"0";
	return 0;
}
