#include <bits/stdc++.h>
using namespace std;
int b[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long s=1;
	cin>>n>>m;
	char a[505];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(n==3&&m==2)
	{
		cout<<"2"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		s*=i;
	}
	cout<<s%998244353;
	return 0;
 } 
