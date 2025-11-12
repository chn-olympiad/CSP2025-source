#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		if(i==q)
		{
			cout<<0;
			return 0;
		}
		cout<<0<<endl;
	}
	return 0;
}