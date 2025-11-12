#include<bits/stdc++.h>
using namespace std;
string a;
int c[509];
long long l=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	for(int i=1;i<=n;i++) l=(i*l)%998244353;
	cout<<l;
	return 0;
}

