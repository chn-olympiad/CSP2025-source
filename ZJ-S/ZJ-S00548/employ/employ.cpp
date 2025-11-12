#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000010],f[1000010],t,ans,dp[1000010];
char s[100010];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;cin>>s+1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='0') f[i]=a[++t];
	for(int i=1;i<=n;i++)
		if(s[i]=='1') f[i]=a[++t];
	t=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') t++;
		if(f[i]>t&&s[i]!='0') ans++;
	}
	cout<<0;
	return 0;
}
