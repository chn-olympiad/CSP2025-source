#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x;
}
#define N 4000010
long long T,n,xx,yy,zz,cc[4],ans,c[4],vis[N];
struct node{
	long long x,y,val,id;
}a[N];
bool cmp(node uu,node ii){
	return uu.val>ii.val;
}
bool check(int x){
	if(x==1){
		if(c[1]+c[2]<cc[3]||c[1]+c[3]<cc[2]||c[1]==0)return 0;
		else return 1;
	}
	if(x==2){
		if(c[2]+c[1]<cc[3]||c[2]+c[3]<cc[1]||c[2]==0)
		return 0;
		else return 1;
	}
	if(x==3){
		if(c[3]+c[1]<cc[2]||c[3]+c[2]<cc[1]||c[3]==0)
		return 0;
		else return 1;
	}
}
bool us[N],cn[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		ans=0;
		n=read();
		cc[1]=cc[2]=cc[3]=0;
		c[1]=c[2]=c[3]=n/2;
		cn[1]=cn[2]=cn[3]=1;
		memset(us,0,sizeof(us));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			xx=read();
			yy=read();
			zz=read();
			ans+=max(max(xx,yy),zz);
			if(xx>=yy&&xx>=zz){
				if(yy>=zz){
					a[2*i]={1,2,xx-yy,i};
					a[2*i+1]={2,3,yy-zz,i+n};
				}else{
					a[2*i]={1,3,xx-zz,i};
					a[2*i+1]={3,2,zz-yy,i+n};
				}
			}
			if(yy>=xx&&yy>=zz){
				if(xx>=zz){
					a[2*i]={2,1,yy-xx,i};
					a[2*i+1]={1,3,xx-zz,i+n};
				}else{
					a[2*i]={2,3,yy-zz,i};
					a[2*i+1]={3,1,zz-xx,i+n};
				}
			}
			if(zz>=xx&&zz>=yy){
				if(xx>=yy){
					a[2*i]={3,1,zz-xx,i};
					a[2*i+1]={1,2,xx-yy,i+n};
				}else{
					a[2*i]={3,2,zz-yy,i};
					a[2*i+1]={2,1,yy-xx,i+n};
				}
			}
		}
//		cout<<"ans="<<ans<<"\n";
		sort(a,a+2*n,cmp);
		for(int i=0;i<2*n;i++){
//			printf("///////////////////\n");
//			printf("%d %d %d %d\n",a[i].x,a[i].y,a[i].id,a[i].val);
//			cout<<ans<<endl;
//			cout<<cn[1]<<" "<<cn[2]<<endl;
//			cout<<c[3]<<endl;
			if(a[i].id<n){
				cc[vis[a[i].id]]--;
				cn[a[i].x]=check(a[i].x);
				if(cn[a[i].x]){
//					cout<<a[i].id<<"->"<<a[i].x<<endl;
					c[a[i].x]--;
					cn[a[i].x]=check(a[i].x);
					us[a[i].id]=1;
				}
				else {
//					cout<<ans<<"**"<<a[i].val<<endl;
					ans-=a[i].val;
				}
			}else{
				if(us[a[i].id-n])continue;
				if(a[i].y==1){
					if(cn[2]||cn[3]){
						vis[a[i].id-n]=1;
						cc[1]++;
						cn[2]=check(2);
						cn[3]=check(3);
					}else ans-=a[i].val;
				}
				if(a[i].y==2){
					if(cn[1]||cn[3]){
						vis[a[i].id-n]=2;
						cc[2]++;
						cn[1]=check(1);
						cn[3]=check(3);
					}else ans-=a[i].val;
				}
				if(a[i].y==3){
					if(cn[1]||cn[2]){
						vis[a[i].id-n]=3;
						cc[3]++;
						cn[1]=check(1);
						cn[2]=check(2);
					}else ans-=a[i].val;
				}
			}
//			cout<<"ans="<<ans<<"\n";
		}
		cout<<ans<<"\n";
	}
}
/*
1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
*/