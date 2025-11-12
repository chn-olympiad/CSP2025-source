#include<bits/stdc++.h>
using namespace std;
//10010+j country`s nod
int n,m,k,fa[10100],ky[20];
long long ans=0x7f,ans1;
bool used[20];
struct edg{
	int l,u,v;
	friend bool operator < (edg a,edg b){
		return a.l<b.l;
	}friend bool operator > (edg a,edg b){
		return a.l>b.l;
	}
	
}way[1001000],psb_w[10100],c[12][10010];
bool cmp(edg a,edg b){
		return a < b;
}
int fnd(int x){
	return x==fa[x]?x:fa[x]=fnd(fa[x]);
}
void uni(int x,int y){
	fa[fnd(x)]=fnd(y);
}
int fndmin(){
	int minn=0;
	for (int j=0;j<k;j++){
		if (c[j][ky[j]].l<c[minn][ky[minn]].l && used[j] && ky[minn]<=n)minn=j;
	}return ky[0]<=n?minn:-1;
}
int main(){
	ans=0x7f7f7f7f7f7f7f7f;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&way[i].u,&way[i].v,&way[i].l);
	}
	sort(way,way+m,cmp);
	memset(c,0x7f,sizeof(c));
	for (int j=0;j<k;j++){
		for (int i=0;i<=n;i++){
			c[j][i].u=10010+j;c[j][i].v=i;
			scanf("%d",&c[j][i].l);
		}sort(c[j]+1,c[j]+n+1,cmp);
	}
	
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}int cur=0,curi=0;
	while (cur<n-1){
		while(fnd(way[curi].u)==fnd(way[curi].v))curi++;
		uni(way[curi].u,way[curi].v);
		psb_w[cur]=way[curi];
		ans1+=1ll*way[curi].l;
		cur++;curi++;
	}ans=min(ans,ans1);
	
	for (int j=0;j<k;j++){
		used[j]=1;ans1=0;int num=0,edgnum[12],lsz[12];
		for (int i=0;i<k;i++){ky[i]=1;ans1+=used[i]?1ll*c[i][0].l:1ll*0;edgnum[i]=lsz[i]=0;fa[10010+i]=10010+i;num+=used[i]?1:0;}
		cur=0,curi=0;edg curr;int minn=fndmin();
		if (c[minn][ky[minn]]<psb_w[curi]){
			curr=c[minn][ky[minn]];
		}else {
			curr=psb_w[curi];
		}
		for (int i=1;i<=n;i++)
			fa[i]=i;
		while (cur<n-1+num){
			while(fnd(curr.u)==fnd(curr.v)){
				minn=fndmin();
				if (minn>=0 && c[minn][ky[minn]]<psb_w[curi] || curi>=n-1){
					curr=c[minn][ky[minn]];
					ky[minn]++;
				}else {
					curr=psb_w[curi];
					curi++;
				}
			}
			if (curr.u>=10010)edgnum[curr.u-10010]++,lsz[curr.u-10010]=curr.l;
			uni(curr.u,curr.v);
			ans1+=1ll*curr.l;
			cur++;
			if (c[minn][ky[minn]]<psb_w[curi]){
				curr=c[minn][ky[minn]];
			}else {
				curr=psb_w[curi];
			}
			if (curr.u>=10010)ky[minn]++;
			else curi++;minn=fndmin();
			
		}
		for (int j=0;j<k;j++){
			if (edgnum[j]==1)ans1-=1ll*(c[j][0].l+lsz[j]);
		}
		if (ans>=ans1){
			ans=ans1;
			for (int j=0;j<k;j++)
				if (edgnum[j]==1)used[j]=0;
		}
	}
	printf("%lld",ans);
	return 0;
}
