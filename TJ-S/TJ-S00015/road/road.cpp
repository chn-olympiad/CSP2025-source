#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
struct di{
	int u,v,w,x;
};
bool cmp(di x,di y){
	return x.w<y.w;
}
int fa[100019];
int cha(int x){
	if(fa[x]!=x){
		fa[x]=cha(fa[x]);
	}
	return fa[x];
}
void me(int x,int y){
	int xx=cha(x),yy=cha(y);
    if(xx!=yy){
    	fa[xx]=yy;
	}
	return;
}
di a[1100009];
int c[13];
int b;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		a[i].u--;
		a[i].v--;
		a[i].x=-1;
	}
	bool ooo=true,ppp;
	for(int i=0;i<k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0){
			ooo=false;
		}
		ppp=false;
		for(int j=0;j<n;j++){
			scanf("%d",&b);
			if(b==0){
				ppp=true;
			}
			a[m].u=n+i;
			a[m].v=j;
			a[m].w=b;
			a[m].x=i;
			m++;
		}
		if(!ppp){
			ooo=false;
		}
	}
	sort(a,a+m,cmp);
	long long sum=0,su=0;
	long long minn=1e18;
	int som=0;
	for(int i=0;i<(1<<k);i++){
		if(ooo){
			i=(1<<k)-1;
		}
	   sum=0;
		su=n;
		for(int j=0;j<n+k;j++){
			fa[j]=j;
		}
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				sum+=c[j];
				su++;
			}
		}
		for(int j=0;j<m;j++){
		    if(su==1){
				break;
			}
			if(cha(a[j].u)!=cha(a[j].v)&&(a[j].x==-1||((i>>a[j].x)&1))){
				me(a[j].u,a[j].v);
				sum+=a[j].w;
				su--;
			}
		}
		minn=min(minn,sum);
	}
	cout<<minn;
	return 0;
}
