#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,mod=998244353,a[10010];
int bo;
string st;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bo=1;
	cin>>st;
	for(int i=0;i<st.size();i++)
	if(st[i]=='0') bo=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ans=1;
	if(bo==1)
	for(int i=1;i<=n;i++) ans=ans*1ll*i%mod;
	cout<<ans<<endl;
	return 0;
}
