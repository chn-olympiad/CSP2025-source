#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,m,k,tot,c[15],a[15][10005],o[1205],fa[10015][1205],cnt[1205],ans[1205];
pair<int,pair<int,int> > e[1100005];
int fd(int x,int j){
	if(fa[x][j]==x) return x;
	return fa[x][j]=fd(fa[x][j],j);
}
void mg(int x,int y,int j){
	x=fd(x,j),y=fd(y,j);
	fa[x][j]=y;
}
int num1(int x){
	int res=0;
	while(x){
		x-=(x&(-x));
		res++;
	}
	return res;
}
int cl(int x){
	int res=0,cnt=0;
	while(x){
		cnt++;
		res+=((x&1)?c[cnt]:0);
		x=(x>>1);
	}
	return res;
}
int rd(){
	int x=0;
	bool f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-') f=0;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f?x:(-x));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,x,y,z;
	n=rd();m=rd();k=rd();
	tot=m;
	for(i=1;i<=m;i++){
		x=rd();y=rd();z=rd();
		e[i]={z,{x,y}};
	}
	for(i=1;i<=k;i++){
		c[i]=rd();
		for(j=1;j<=n;j++){
			a[i][j]=rd();
			tot++;
			e[tot]={a[i][j],{n+i,j}};
		}
	}
	for(i=0;i<10015;i++){
		for(j=0;j<1205;j++){
			fa[i][j]=i;
		}
	}
	for(i=0;i<(1<<k);i++){
		cnt[i]=n+num1(i);
		ans[i]=cl(i);
	}
	sort(e+1,e+1+tot);
	for(i=1;i<=tot;i++){
		x=e[i].second.first,y=e[i].second.second,z=e[i].first;
		if(x>n){
			for(j=1;j<(1<<k);j++){
				if(!((j>>(x-n-1))&1)) continue;
				if(cnt[j]!=1&&fd(x,j)!=fd(y,j)){
					cnt[j]--,ans[j]+=z;
					mg(x,y,j);
				}
			}
		}
		else{
			for(j=0;j<(1<<k);j++){
				if(cnt[j]!=1&&fd(x,j)!=fd(y,j)){
					cnt[j]--,ans[j]+=z;
					mg(x,y,j);
				}
			}
		}
	}
	z=2e18;
	for(i=0;i<(1<<k);i++){
		z=min(z,ans[i]);
	}
	printf("%lld",z);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
