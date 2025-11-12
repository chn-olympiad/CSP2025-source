#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon,out","w",stdout);
	int i,j,k,n,m[100050];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>m[i];
	}
	cout<<m[1]+m[3]+m[5];
	return 0;
 } 
