#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m,s,c[1010],ans=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
    return 0;
}

