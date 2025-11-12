#include <bits/stdc++.h>
#define int long long
#define JTB ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int MAXN=510;
const int MOD=998244353;
int n,m,ans,s[MAXN],c[MAXN],sum;
char str[MAXN];
signed main(){
	JTB
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str+1;
	for(int i=1;i<=n;i++)sum=sum+(str[i]-'0');
	for(int i=1;i<=n;i++)cin>>c[i];
	if(sum==n){//A
		ans=1;
		for(int i=n;i>n-m;i--){
			ans=(ans*i)%MOD;
		}	
	}
	cout<<ans<<endl;
	return 0;
}
