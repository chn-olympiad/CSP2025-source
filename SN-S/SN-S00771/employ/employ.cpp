#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[50005];
long long ans;

int main()
{
	freopen("employ,in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getline(cin,s);
	getline(cin,s);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=ans*i%998244353;
	}
		cout<<ans;
	return 0;
}
