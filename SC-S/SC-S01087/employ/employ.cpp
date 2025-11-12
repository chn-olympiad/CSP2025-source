#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	long long ans=1;
	for(int i=1;i<=n;i++)	ans*=i;
	printf("%lld",ans);
	return 0;
}