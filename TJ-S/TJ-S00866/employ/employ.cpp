#include <bits/stdc++.h>
using namespace std;
int b[1005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	int flag=0;
	int e=count(a.begin(),a.end(),'1');
	int d=1;
	if(e==n)
	{
		for(int i=n;i>=1;i--)
		{
			d*=i;
		}
	}
	cout<<d;
	return 0;
}
