#include<cstdio>
int a[10],b[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		long long ans=0;
		int x1=0,x2=0,x3=0;
		for(int j=1;j<=t;j++){
			for(int x=1;x<=3;x++){
				scanf("%d",&a[x]);
			}
			b[1]=a[1],b[2]=a[2],b[3]=a[3];
			for(int x=1;x<3;x++){
				for(int y=1;y<=3;y++){
					if(a[y]<a[y+1]){
						int t=a[y];
						a[y]=a[y+1];
						a[y+1]=t;
					}
				}
			}
			int f=1;
			if(a[1]==b[1]){
				x1++;
			}
			if(a[1]==b[2]){
				x2++;
			}
			if(a[1]==b[3]){
				x3++;
			}
			if(x1>t/2){
				if(x2>t/2){
					ans+=a[3],f=0;
				}else{
					ans+=a[2],f=0;
				}
			}
			if(x2>t/2){
				if(x2>t/2){
					ans+=a[3],f=0;
				}else{
					ans+=a[2],f=0;
				}
			}
			if(x3>t/2){ 
				if(x2>t/2){
					ans+=a[3],f=0;
				}else{
					ans+=a[2],f=0;
				}
			}
			if(f==1) ans+=a[1];
		}
		printf("%lld\n",ans);
		ans=0;
	} 
	return 0;
}
