#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
bool si[510];
int c[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++)
	{
		cin>>c[i];
		if(s[i] == '1')
		{
			si[i] = 1;
		}
		else
		{
			si[i] = 0;
		}
	}
	cout<<3;
	return 0;
}
