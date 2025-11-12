#include<bits/stdc++.h>
using namespace std;
const int slen=1e5+10;
int t,n,s[4];
struct info{
	int a,b,c,w,bh;
}r[slen];
bool cmp(info x,info y){
	return x.w>y.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int o=1;o<=t;o++){
		scanf("%d",&n);
		memset(r,0,sizeof(r));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&r[i].a,&r[i].b,&r[i].c);
			r[i].w=max(r[i].a,max(r[i].b,r[i].c));
			if(r[i].w==r[i].a) r[i].bh=1;
			if(r[i].w==r[i].b) r[i].bh=2;
			if(r[i].w==r[i].c) r[i].bh=3;
		}
		sort(r+1,r+n+1,cmp);
		int ans=0,k=n/2;
		memset(s,0,sizeof(s));
		if(n==2){
			for(int i=1;i<=3;i++){
				int x;
				if(i==1)x=r[1].a;
				if(i==2)x=r[1].b;
				if(i==3)x=r[1].c;
				for(int j=1;j<=3;j++){
					if(i==j)continue;
					if(j==1)ans=max(ans,x+r[2].a);
					if(j==2)ans=max(ans,x+r[2].b);
					if(j==3)ans=max(ans,x+r[2].c);
				}
			}
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			int x1,x2,y1,y2;
			if(r[i].bh==1){
				if(s[1]<k){s[1]++;ans+=r[i].a;continue;}
				if(r[i].b==r[i].c){
					if(s[2]<s[3]){x1=2;x2=3;y1=r[i].b;y2=r[i].c;}
					else{x1=3;x2=2;y1=r[i].c;y2=r[i].b;}
				}
				if(r[i].b>r[i].c){x1=2;x2=3;y1=r[i].b;y2=r[i].c;}
				if(r[i].b<r[i].c){x1=3;x2=2;y1=r[i].c;y2=r[i].b;}
			}
			if(r[i].bh==2){
			if(s[2]<k){s[2]++;ans+=r[i].b;continue;}
				if(r[i].a==r[i].c){
					if(s[1]<s[3]){x1=1;x2=3;y1=r[i].a;y2=r[i].c;}
					else{x1=3;x2=1;y1=r[i].c;y2=r[i].a;}
				}
				if(r[i].a>r[i].c){x1=1;x2=3;y1=r[i].a;y2=r[i].c;}
				if(r[i].a<r[i].c){x1=3;x2=1;y1=r[i].c;y2=r[i].a;}
			}
			if(r[i].bh==3){
				if(s[3]<k){s[3]++;ans+=r[i].c;continue;}
				if(r[i].a==r[i].b){
					if(s[1]<s[2]){x1=1;x2=2;y1=r[i].a;y2=r[i].b;}
					else{x1=2;x2=1;y1=r[i].b;y2=r[i].a;}
				}
				if(r[i].a>r[i].b){x1=1;x2=2;y1=r[i].a;y2=r[i].b;}
				if(r[i].a<r[i].b){x1=2;x2=1;y1=r[i].b;y2=r[i].a;}
			}
			if(s[x1]<k){s[x1]++;ans+=y1;continue;}
			else {s[x2]++;ans+=y2;}
		}
		printf("%d\n",ans);
	}
	return 0;
}