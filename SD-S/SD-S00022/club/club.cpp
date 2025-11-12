#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans,ca,cb,cc,x[N],y[N],z[N],b[N];
struct node{
	int a,b,c,id;
}a[N];
void move(int x[],int ca,int f){
	for(int i=1;i<=ca;i++){
		if(f==1) b[i]=max(a[x[i]].b-a[x[i]].a,a[x[i]].c-a[x[i]].a);
		else if(f==2) b[i]=max(a[x[i]].a-a[x[i]].b,a[x[i]].c-a[x[i]].b);
		else b[i]=max(a[x[i]].a-a[x[i]].c,a[x[i]].b-a[x[i]].c);
	}
	sort(b+1,b+ca+1);
	for(int i=(n>>1)+1;i<=ca;i++){
		ans+=b[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ca=cb=cc=ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			int m=max(max(a[i].a,a[i].b),a[i].c);
			if(m==a[i].a){
				x[++ca]=i;
				ans+=a[i].a;
			}
			else if(m==a[i].b){
				y[++cb]=i;
				ans+=a[i].b;
			}
			else if(m==a[i].c){
				z[++cc]=i;
				ans+=a[i].c;
			}
		}
		int m=max(max(ca,cb),cc);
		if(m>(n>>1)){
			if(m==ca){
				move(x,ca,1);
			}
			else if(m==cb){
				move(y,cb,2);
			}
			else{
				move(z,cc,3);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
