/*********************************************************************
    程序名: 
    版权: 
    作者: 
    日期: 2025-11-01 16:05
    说明: 
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct line{
	int from,to,w;
}l[2000010];
int fa[20010];
int fd(int x){
	if(fa[x]==x)return x;
	return fa[x]=fd(fa[x]);
}
void unionn(int x,int y){
	int dx=fd(x);
	int dy=fd(y);
	if(dx!=dy){
		fa[dx]=dy;
	}
}
int n,m,k,w[20];
bool f[20010],ch[20];
int num[20],cst[20];
bool cmp(line x,line y){
	return x.w<y.w;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&l[i].from,&l[i].to,&l[i].w);
	int cnt=m;
	for(int i=1;i<=k;i++){
		scanf("%lld",&w[i]);
		for(int j=1;j<=n;j++){
			int x;
			scanf("%lld",&x);
			cnt++;
			l[cnt].from=n+i;
			l[cnt].to=j;
			l[cnt].w=x;
		}
	}
	
	int anss=LLONG_MAX;
	sort(l+1,l+1+cnt,cmp);
//	for(int i=1;i<=cnt;i++)cout<<l[i].from<<' '<<l[i].to<<' '<<l[i].w<<endl;
	for(int x=0;x<=((1<<k)-1);x++){
		memset(num,0,sizeof num);
		memset(cst,0,sizeof cst);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int xx=x,ans=0,chnum=0;
		for(int i=1;i<=k;i++){
			if(xx%2==1){
				ch[i]=true;
				chnum++;
			}
			else ch[i]=false;
			xx=xx/2;
//			cout<<ch[i]<<' ';
		}
//		cout<<endl;
		int pnum=0;
		for(int i=1;i<=cnt;i++){
			if(pnum==n+chnum-1)break;
			if(fd(l[i].from)!=fd(l[i].to)){
				if(l[i].from>n and !ch[l[i].from-n])continue;
				pnum++;
				unionn(l[i].from,l[i].to);
				ans+=l[i].w;
				if(l[i].from>n){
					num[l[i].from-n]++;
					cst[l[i].from-n]+=l[i].w;
				}
			}
		}
		for(int i=1;i<=k;i++){
			if(!ch[i])continue;
			if(num[i]==1){
				ans-=cst[i];
			}else{
				ans+=w[i];
			}
		}
		anss=min(anss,ans);
//		for(int i=1;i<=k;i++){
//			cout<<num[i]<<' ';
//		}cout<<endl;
//		cout<<ans<<'\n';
	}
	cout<<anss;
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