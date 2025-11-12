#include<bits/stdc++.h>
using namespace std;
int n,t,tong[5];
long long ans;
struct Leo{
	int a,b,c,zx,jz;
}x[100100];
int cmp(Leo xx,Leo yy){
	if(xx.zx==yy.zx) return xx.jz>yy.jz;
	else return xx.zx>yy.zx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		tong[1]=tong[2]=tong[3]=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a,b,c,d,zhx;
			scanf("%d%d%d",&a,&b,&c);
			d=max(a,max(b,c));
			ans+=d;
			x[i].a=d-a;x[i].b=d-b;x[i].c=d-c;
			zhx=x[i].a+x[i].b+x[i].c;
			x[i].jz=max(x[i].a,max(x[i].b,x[i].c))*2-zhx;
			x[i].zx=(zhx-x[i].jz)/2;
		}
		sort(x+1,x+1+n,cmp);
		for(int i=1;i<=n;i++){
			int minn=min(x[i].a,min(x[i].b,x[i].c));
			if(minn==x[i].a){
				if(tong[1]<n/2) tong[1]++;
				else{
					if(x[i].zx==x[i].b) tong[2]++,ans-=x[i].zx;
					else tong[3]++,ans-=x[i].zx;
				}
			}
			else if(minn==x[i].b){
				if(tong[2]<n/2) tong[2]++;
				else{
					if(x[i].zx==x[i].a) tong[1]++,ans-=x[i].zx;
					else tong[3]++,ans-=x[i].zx;
				}
			}
			else{
				if(tong[3]<n/2) tong[3]++;
				else{
					if(x[i].zx==x[i].b) tong[2]++,ans-=x[i].zx;
					else tong[1]++,ans-=x[i].zx;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
