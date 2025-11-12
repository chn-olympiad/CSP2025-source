#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[10025],siz[10025],gt[15],c[15],hd[15];
int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return x;
}
void uni(int x,int y){
	if(siz[find(x)]>siz[find(y)]){
		fa[find(y)]=find(x);
		siz[find(x)]+=siz[find(y)];
	}
	else{
		fa[find(x)]=find(y);
		siz[find(y)]+=siz[find(x)];
	}
}
struct node{
	int u,v,w;
}a[1000055],h[15][10005];
int getint(){
	char ch=getchar();
	int res=0;
	while(!(ch>='0'&&ch<='9')) ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	return res;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=getint();m=getint();k=getint();
	for(int i=1;i<=m;i++){
		a[i].u=getint();a[i].v=getint();a[i].w=getint();
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++){
		c[i]=getint();
		for(int j=1;j<=n;j++){
			h[i][j].w=getint();
			h[i][j].v=j;h[i][j].u=n+i;
		}
		sort(h[i]+1,h[i]+n+1,cmp);
	}
	long long ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			ans+=1ll*a[i].w;
			uni(a[i].u,a[i].v);
			cnt++;
			h[0][cnt]=a[i];
		}
		if(cnt==n-1){
			break;
		}
	}
//	cerr<<"HACK"<<endl;
	for(int t=1;t<(1<<k);t++){
		int i=t;
		int ct=1;
		gt[1]=0;
		long long tans=0;
		for(int j=1;j<=n;j++) fa[j]=j,siz[j]=1;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				gt[++ct]=j+1;
				hd[j+1]=1;
				tans+=c[j+1];
				fa[n+j+1]=n+j+1;
				siz[n+j+1]=1;
			}
		}
		//cerr<<i<<" "<<"?"<<endl;
		if(tans>ans) continue;
		hd[0]=1;
		//cerr<<i<<" !"<<endl;
		int tcnt=0;
		for(int j=1;j<=n*(ct+1)-1;j++){
			int mng=1;
			if(hd[gt[1]]>=n) break;
			for(int l=2;l<=ct;l++){
				if(hd[gt[l]]>=n) continue;
				//if(i>=129) cerr<<i<<" "<<l<<" "<<gt[l]<<" "<<hd[gt[l]]<<endl;
				if(h[gt[l]][hd[gt[l]]].w<h[gt[mng]][hd[gt[mng]]].w){
					mng=l;
				}
			}
			int tu=h[gt[mng]][hd[gt[mng]]].u,tv=h[gt[mng]][hd[gt[mng]]].v;
			//if(i>=129) cerr<<tu<<" "<<tv<<endl;
			if(find(tu)!=find(tv)){
				//if(tcnt%100==0) cerr<<i<<" "<<tcnt<<":"<<tu<<" "<<tv<<endl;
				uni(tu,tv);
				tans+=h[gt[mng]][hd[gt[mng]]].w;
				tcnt++;
				if(tans>ans||tcnt==n+ct-2){
					break;
				}
			}
			hd[gt[mng]]++;
		}
		//cerr<<i<<" "<<tans<<endl;
		ans=min(tans,ans);
	}
//	for(int i=0;i<(1<<k);i++){
//		cerr<<i<<" "<<gtt[i]<<endl;
//	}
	printf("%lld\n",ans);
	return 0;
}//I win,I lose.--LuoXH
