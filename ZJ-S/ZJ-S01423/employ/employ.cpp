#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) ans=ans*i%MOD;
	cout<<ans;
	return 0;
}