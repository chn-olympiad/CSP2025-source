#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
int t;
struct node{
	int a,b,c;
}g[maxn];
int choice[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&g[i].a,&g[i].b,&g[i].c);
		}
		int na=0,nb=0,nc=0;
		for(int i=1;i<=n;i++){
			int maxx=-1,p1=0,pos=0,p2=0;
			if(na<n/2){
				if(g[i].a>maxx){
					maxx=g[i].a;
					p1=1;
				}
			}else{
				for(int j=1;j<i;j++){
					if(choice[j]==1){
						if(nb<n/2){
							if(g[i].a+g[j].b-g[j].a>maxx){
								maxx=g[i].a+g[j].b-g[j].a;
								p1=1;
								pos=j;
								p2=2;
							}
						}
						if(nc<n/2){
							if(g[i].a+g[j].c-g[j].a>maxx){
								maxx=g[i].a+g[j].c-g[j].a;
								p1=1;
								pos=j;
								p2=3;
							}
						}
					}
				}
			}
			if(nb<n/2){
				if(g[i].b>maxx){
					maxx=g[i].b;
					p1=2;
				}
			}else{
				for(int j=1;j<i;j++){
					if(choice[j]==2){
						if(na<n/2){
							if(g[i].b+g[j].a-g[j].b>maxx){
								maxx=g[i].b+g[j].a-g[j].b;
								p1=2;
								pos=j;
								p2=1;
							}
						}
						if(nc<n/2){
							if(g[i].b+g[j].c-g[j].b>maxx){
								maxx=g[i].b+g[j].c-g[j].b;
								p1=2;
								pos=j;
								p2=3;
							}
						}
					}
				}
			}
			if(nc<n/2){
				if(g[i].c>maxx){
					maxx=g[i].c;
					p1=3;
				}
			}else{
				for(int j=1;j<i;j++){
					if(choice[j]==3){
						if(na<n/2){
							if(g[i].c+g[j].a-g[j].c>maxx){
								maxx=g[i].c+g[j].a-g[j].c;
								p1=3;
								pos=j;
								p2=1;
							}
						}
						if(nb<n/2){
							if(g[i].c+g[j].b-g[j].c>maxx){
								maxx=g[i].c+g[j].b-g[j].c;
								p1=3;
								pos=j;
								p2=2;
							}
						}
					}
				}
			}
			ans+=maxx;
			choice[i]=p1;
			if(pos!=0)choice[pos]=p2;
			if(p2==0){
				if(p1==1)na++;
				if(p1==2)nb++;
				if(p1==3)nc++;
			}else{
				if(p2==1)na++;
				if(p2==2)nb++;
				if(p2==3)nc++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
