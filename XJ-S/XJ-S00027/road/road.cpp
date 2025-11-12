#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10000],b[100000],c[100000],s[100000],m,v[100000];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,q;
	cin>>m>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=q;i++)
	for(int j=1;j<=m+1;j++)
	cin>>s[i];
	for(int i=1;i<=n;i++)
	t+=c[i];
	cout<<t;
	return 0;
} 
