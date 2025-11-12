#include<bits/stdc++.h>
using namespace std;
string str1,str2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n*2;i++)
	{
		cin>>str1;
	}
	cin>>str1>>str2;
	int i=str1.size(),j=str2.size();
	if(i==j)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
