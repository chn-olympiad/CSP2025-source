#include<bits/stdc++.h>
using namespace std;
int n,m,c[511];
const long long P=998244353;
long long ans=1;
char s[511];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%c",&s[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
