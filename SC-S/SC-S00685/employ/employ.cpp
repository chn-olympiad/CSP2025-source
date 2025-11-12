#include <bits/stdc++.h>
using namespace std;
char q[1000];
int a[1000];
int main()
{
	int n,m;
	cin>>n>>m;
		freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);

	cin>>q;
	int s=1,i;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		s*=i;
		s%=998244353;
		
	}
	cout<<s;
	return 0;
}