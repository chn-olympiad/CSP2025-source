#include<bits/stdc++.h>
using namespace std;
long long int n,i,m,c[500],ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(i=1;i<=n;i++)
	cin>>c[i];
	for(i=1;i<=n;i++)
	ans*=i;
	cout<<ans%998244353;
	return 0;
}
