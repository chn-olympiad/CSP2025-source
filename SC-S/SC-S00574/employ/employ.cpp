#include<bits/stdc++.h>
using namespace std;
long long n,m,c[5005],vis[5005],ans;
char s[5005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>s[i];
	for(long long i=1;i<=n;i++)cin>>c[i];
	ans=1;
	for(long long i=n-m+1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}