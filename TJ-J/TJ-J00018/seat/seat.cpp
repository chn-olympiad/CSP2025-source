#include<cstdio>
#include<algorithm>
int n,m;
int a[112];
int b1[112];
int b2[112];
int k=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int t=a[1];
	std::sort(&a[1],&a[n*m]+1);
	//for(int i=1;i<=n*m;i++)printf("%3d%3d\n",i,a[i]);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				b1[++k]=i;
				b2[k]=j;
				//printf("%3d%3d%3d\n",k,b1[k],b2[k]);
			}
		}else{
			for(int j=n;j>=1;j--){
				b1[++k]=i;
				b2[k]=j;
				//printf("%3d%3d%3d\n",k,b1[k],b2[k]);
			}
		}
	}
	for(int i=1;i<=n*m;i++)if(a[i]==t)t=n*m+1-i;
	//printf("%d\n",t);
	printf("%d %d\n",b1[t],b2[t]);
	return 0;
}
