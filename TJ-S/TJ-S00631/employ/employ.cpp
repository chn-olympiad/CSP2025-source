#include<bits/stdc++.h>
using namespace std;
int n,m,a[501];
long long b[501];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s>>a[1];
	b[1]=1;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]*i;
	}
	cout<<b[n]<<'\n';
	return 0;
}
