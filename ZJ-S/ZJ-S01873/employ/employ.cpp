#include<stdio.h>
const int mod=998244353;
namespace{
	int n,m,c[505],flag=1;
	char s[505];
}
int main(){
	freopen("employ.in","r",stdin);
	freopne("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",c+i);
	for(int i=1;i<=n;i++)
		if(s[i]!=1){flag=0;break;}
	if(flag){
		int ans=1;
		for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}