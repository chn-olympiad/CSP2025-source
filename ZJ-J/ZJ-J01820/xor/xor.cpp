#include<stdio.h>
const int N=5e5+5;
namespace{
	int n,k,a[N],pre[N],f[N][3];
}
int max(int a,int b){return a>b? a:b;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i),pre[i]=pre[i-1]^a[i];
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		for(int j=i;j;j--)
			if((pre[i]^pre[j-1])==k){
				f[i][1]=max(f[i][1],max(f[j-1][1],f[j-1][0])+1);
				break;
			}
	}
	printf("%d",max(f[n][0],f[n][1]));
	fclose(stdin);fclose(stdout);
	return 0;
}