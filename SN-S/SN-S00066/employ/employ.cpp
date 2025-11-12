#include <bits/stdc++.h>
using namespace std;
long long b[10010],c=1;
char a[10100];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>m>>n;
	
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		if(b[i]!=0)
			c*=b[i];
		
	}
	cout<<c;
	return 0;
}
