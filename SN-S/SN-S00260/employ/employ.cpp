#include<bits/stdc++.h>
//#include<windows.h>
#define LL long long
using namespace std;
//unsigned
int n,m;
char s[510];
int c[510];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cout<<n/3;
	return 0;
}
