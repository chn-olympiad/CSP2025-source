#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}q[1000001];
bool cmp(node x,node y){
	return max(max(x.a,x.b),x.c)>max(y.a,max(y.b,y.c));
}
bool cmpa(node x,node y){
	return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);
}
bool cmpb(node x,node y){
	return x.b-max(x.a,x.c)>y.b-max(y.a,y.c);
}
bool cmpc(node x,node y){
	return x.c-max(x.a,x.b)>y.c-max(y.a,y.b);
}
int n,h[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);	
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&q[i].a,&q[i].b,&q[i].c);
		}
		sort(q+1,q+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(q[i].a==max(q[i].a,max(q[i].b,q[i].c))){
				h[1]++;
			}else if(q[i].b==max(q[i].a,max(q[i].b,q[i].c))){
				h[2]++;
			}else{
				h[3]++;
			}
		}
		if(h[1]>n/2){
			sort(q+1,q+1+n,cmpa);
			h[1]=0;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(h[1]==n/2)q[i].a=-1;
				ans+=max(q[i].a,max(q[i].b,q[i].c));
				if(q[i].a==max(q[i].a,max(q[i].b,q[i].c))){
					h[1]++;
				}
			}
			printf("%d\n",ans);
		}else if(h[2]>n/2){
			h[2]=0;
			int ans=0;
			sort(q+1,q+1+n,cmpb);
			for(int i=1;i<=n;i++){
				if(h[2]==n/2)q[i].b=-1;
				ans+=max(q[i].a,max(q[i].b,q[i].c));
				if(q[i].b==max(q[i].a,max(q[i].b,q[i].c))){
					h[2]++;
				}
			}
			printf("%d\n",ans);
		}else if(h[3]>n/2){
			h[3]=0;
			int ans=0;
			sort(q+1,q+1+n,cmpc);
			for(int i=1;i<=n;i++){
				if(h[3]==n/2)q[i].c=-1;
				ans+=max(q[i].a,max(q[i].b,q[i].c));
				if(q[i].c==max(q[i].a,max(q[i].b,q[i].c))){
					h[3]++;
				}
			}
			printf("%d\n",ans);
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(q[i].a,max(q[i].b,q[i].c));
			}
			printf("%d\n",ans);
		}
		h[1]=h[2]=h[3]=0;
	} 
}
/*
不是，S组这么炸吗，上来一道逆天贪心

还好赛前有加练，不然报零了。

大概是排序一手，然后推一下式子 

严格难于上午任意一道题。 

*/