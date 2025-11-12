#include<bits/stdc++.h>
using namespace std;
int a[10010];
int m,n;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	cout<<m<<" "<<n;
	return 0;
} 
