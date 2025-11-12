#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int t,n,pa,pb,pc,ans;
struct ppl{
	int ma,mb,mc;
}a[100005],b[50005];
bool cmpa(ppl x,ppl y){
	return (x.ma-max(x.mb,x.mc))<(y.ma-max(y.mb,y.mc));
}
bool cmpb(ppl x,ppl y){
	return (x.mb-max(x.ma,x.mc))<(y.mb-max(y.ma,y.mc));
}
bool cmpc(ppl x,ppl y){
	return (x.mc-max(x.mb,x.ma))<(y.mc-max(y.mb,y.ma));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		pa=0;
		pb=0;
		pc=0;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].ma,&a[i].mb,&a[i].mc);
			if(a[i].ma>=a[i].mb&&a[i].ma>=a[i].mc){
				pa++;
				ans+=a[i].ma;
			}else if(a[i].mb>=a[i].ma&&a[i].mb>=a[i].mc){
				pb++;
				ans+=a[i].mb;
			}else{
				pc++;
				ans+=a[i].mc;
			}
		}
		if(pa>n/2){
			int k=0;
			for(int i=1;i<=n;i++){
				if(a[i].ma>=a[i].mb&&a[i].ma>=a[i].mc){
					b[k++]=a[i];
				}
			}
			sort(b,b+k,cmpa);
			for(int i=0;i<(pa-n/2);i++){
				ans-=(b[i].ma-max(b[i].mb,b[i].mc));
			}
		}else if(pb>n/2){
			int k=0;
			for(int i=1;i<=n;i++){
				if(a[i].mb>=a[i].ma&&a[i].mb>=a[i].mc){
					b[k++]=a[i];
				}
			}
			sort(b,b+k,cmpb);
			for(int i=0;i<(pb-n/2);i++){
				ans-=(b[i].mb-max(b[i].ma,b[i].mc));
			}
		}else if(pc>n/2){
			int k=0;
			for(int i=1;i<=n;i++){
				if(a[i].mc>=a[i].ma&&a[i].mc>=a[i].mb){
					b[k++]=a[i];
				}
			}
			sort(b,b+k,cmpc);
			for(int i=0;i<(pc-n/2);i++){
				ans-=(b[i].mc-max(b[i].ma,b[i].mb));
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
