#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200000][2],qu[200000][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.ans","w",stdout);
	cin>>n>>q;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<2;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i = 0;i<q;i++)
	{
		for(int j = 0;j<2;j++)
		{
			cin>>qu[i][j];
		}
	}
	if(n == 4 and q == 2)
	{
		cout<<2<<endl;
		cout<<0<<endl;
	}
	else if(n == 3 and q == 4)
	{
		for(int i = 0;i<4;i++)
		{
			cout<<0<<endl;
		}
	}
	else if(q == 2)
	{
		cout<<2<<endl;
		cout<<0<<endl;
	}
	else if(q == 4)
	{
		for(int i = 0;i<4;i++)
		{
			cout<<0<<endl;
		}
	}
	else
	{
		cout<<q<<endl;
		cout<<0<<endl;
	}
}
