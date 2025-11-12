#include <iostream>
#include <cstdio>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	int c;
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	printf("%lld",ans);
	return 0;
}
