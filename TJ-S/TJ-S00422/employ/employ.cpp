#include<bits/stdc++.h>
using namespace std;
long long ans=1,mod=998244353;
string a;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>a;
	for(int i=1;i<=m;i++){int w;scanf("%d",&w);ans*=i;ans%=mod;}
	printf("%lld",ans);
	return 0;
}
