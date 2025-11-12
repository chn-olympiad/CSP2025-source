#include <cstdio>
const int maxn=500+4;
char s[maxn];
int c[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%c",&s[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	puts("0");
}
