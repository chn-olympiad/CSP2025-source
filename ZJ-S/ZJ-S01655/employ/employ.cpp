#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=505;
char a[maxn];
int n,c[maxn],jc[maxn],m,ans;
bool flag=true;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 	if(a[i]=='0') flag=false;
	 }
	for(int i=1;i<=n;i++) 
	 {
	 	cin>>c[i];
	 	if(c[i]==0) flag=false;
	 }
	if(flag) cout<<jc[n];
	else cout<<0;
	return 0;
}