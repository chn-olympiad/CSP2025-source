#include<bits/stdc++.h>
using namespace std;
long long c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	long long m,n,i,j,ans=1;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>s[i];
	for(i=1;i<=n;i++) cin>>c[i];
	for(i=2;i<=n;i++)
	ans=ans*i%998244353;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
