#include<bits/stdc++.h>
using namespace std;
int n,m,b[505],c[505],weizhi[505];
long long jc[505],ans;
char S[505];
void solve(int x,int y,int z) {//y:taotai z:tongguo
	//printf("%d %d %d\n",x,y,z);
	if (z==m) {
		//printf("%d %d %d\n",x,y,z);
		ans=(ans+jc[n-y-z])%998244353;
		return;
	}
	if (x>n) return;
	int tao=0;
 	for (int i=1;i<=n;i++) {
		if (b[i]==0) {
			if (y>=c[i]) {
				b[i]=1;
				weizhi[++tao]=i;
			}
		}
	}
	for (int i=1;i<=n;i++) {
		if (b[i]==0) {
			b[i]=1;
			if (S[i]=='1') solve(x+1,y+tao,z+1);
			else solve(x+1,y+tao+1,z);
			b[i]=0;
		}
	}
	for (int i=1;i<=tao;i++) {
		b[weizhi[i]]=0;
	}//huanyuan
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",S+1);
	for (int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
	}
	jc[0]=1;
	for (int i=1;i<=n;i++) jc[i]=jc[i-1]*i%998244353;
	if (m==n) {
		for (int i=1;i<=strlen(S);i++)
		if (S[i]=='0') {
			printf("0");
			return 0;
		}
		for (int i=1;i<=n;i++) 
		if (c[i]==0) {
			printf("0");
			return 0;
		}
		ans=jc[n]*jc[n]%998244353;
		printf("%lld",ans);
		return 0;
	}
	else {
		solve(1,0,0);
		printf("%lld",ans);
		return 0;
	}
}
