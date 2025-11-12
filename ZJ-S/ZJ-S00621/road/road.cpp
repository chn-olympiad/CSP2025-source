#include<bits/stdc++.h>//15:49 pass all samples,但是不稳,很虚//17:46修改一个错误 
using namespace std;
int n,m,k,fa[100005],a[15][100005],siz[100005],cnt,sz;
long long ans;
struct edge{
	int x,y,z;
}e[1000005],b[100005],c[100005],d[100005];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
bool cmp(edge x,edge y){
	return x.z<y.z;
}
bool vis[100005];
int read(){
	int r=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch&15),ch=getchar();
	return r*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)e[i].x=read(),e[i].y=read(),e[i].z=read();
	for(int i=1;i<=k;i++)
	for(int j=0;j<=n;j++){
	  a[i][j]=read();
	  if(j)c[++cnt]=(edge){i+n,j,a[i][j]};
}
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	sort(e+1,e+1+m,cmp);
	sort(c+1,c+1+cnt,cmp);
	int tot=0;
	for(int i=1;i<=m&&tot<n-1;i++){
		int fx=getfa(e[i].x),fy=getfa(e[i].y);
	    if(fx==fy)continue;
	    if(siz[fx]<siz[fy])swap(fx,fy);
	    fa[fy]=fx;
	    siz[fx]+=siz[fy];
	    ans+=e[i].z;
	    b[++tot]=(edge){e[i].x,e[i].y,e[i].z};
	}
	for(int i=1;i<1<<k;i++){
		long long sum=0;
		int tot=n-1;
		sz=0;
		for(int j=0;j<k;j++)vis[j+1]=(i>>j)&1;
		for(int j=0;j<k;j++)if(vis[j+1])sum+=a[j+1][0],tot++;
		for(int j=1;j<=n+k;j++)fa[j]=j,siz[j]=1;
		for(int j=1;j<=cnt;j++){
		  if(vis[c[j].x-n])d[++sz]=c[j];
	}
		int l=1,r=1;
		while(tot){
			if(l>n-1||(r<=sz)&&d[r].z<b[l].z){
				  int fx=getfa(d[r].x),fy=getfa(d[r].y);
	  			  if(fx==fy){r++;continue;}
	   			  if(siz[fx]<siz[fy])swap(fx,fy);
	   			  fa[fy]=fx;
	    	      siz[fx]+=siz[fy];
	    		  sum+=d[r].z;
	    		  r++,tot--;
			}else{
				  int fx=getfa(b[l].x),fy=getfa(b[l].y);
	  			  if(fx==fy){l++;continue;}
	   			  if(siz[fx]<siz[fy])swap(fx,fy);
	   			  fa[fy]=fx;
	    	      siz[fx]+=siz[fy];
	    		  sum+=b[l].z;
	    		  l++,tot--;
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
