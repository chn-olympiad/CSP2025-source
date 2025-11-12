#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
ll ans=1;
int n,m,c[506],n1=0;
char s[506];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i = 1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]) n1++;
	}
	for(int i = 2;i<=n1;i++){
		ans = (ans*i)%MOD;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
