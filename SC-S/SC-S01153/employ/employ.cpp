#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxn=502,mod=998244353;
int n,m,a[mxn];
string dif;
ll ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>dif;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	printf("%lld",ans);
}