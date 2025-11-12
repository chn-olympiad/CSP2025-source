#include<bits/stdc++.h>
using namespace std;
int n,m,a[510];string s;bool ok=1;
long long ans;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);cin>>s;s=' '+s;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(s[i]=='0')ok=0;
	}
	if(ok==1){
		long long cnt=1;
		for(long long i=n;i>=1;i--){
			cnt*=i;
			if(cnt>=mod)cnt-=mod;
		}
		printf("%lld",cnt);
		return 0;
	}
	return 0;
}//0pts
