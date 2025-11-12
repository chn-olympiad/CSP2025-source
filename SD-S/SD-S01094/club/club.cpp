#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int T,n;
ll ans;
int g[MAXN][3];
int f[3][MAXN],la,lb,lc;
int maxt(int a,int b,int c){
	return max(max(a,b),c);
}
bool cmp(int x,int y){
	int xa=g[x][0],xb=g[x][1],xc=g[x][2];
	int ya=g[y][0],yb=g[y][1],yc=g[y][2];
	if(maxt(xa,xb,xc)==xa&&maxt(ya,yb,yc)==ya)return xa-max(xb,xc)<ya-max(yb,yc);
	if(maxt(xa,xb,xc)==xb&&maxt(ya,yb,yc)==yb)return xb-max(xa,xc)<yb-max(ya,yc);
	return xc-max(xa,xb)<yc-max(ya,yb);
}
inline int read(){
	int x=0;bool f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f?x:-x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=ans=la=lb=lc=0;
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		n=read();
		for(int i=1;i<=n;i++){
			int x=read(),y=read(),z=read();
			g[i][0]=x,g[i][1]=y,g[i][2]=z;
			if(maxt(x,y,z)==x)f[0][++la]=i;
			else if(maxt(x,y,z)==y)f[1][++lb]=i;
			else f[2][++lc]=i;
		}//社团 长度 
		int k=maxt(la,lb,lc),p,cnt,lt=1;
		if(k==la)p=0,cnt=la;
		else if(k==lb)p=1,cnt=lb;
		else p=2,cnt=lc;
		sort(f[p]+1,f[p]+cnt+1,cmp);
		for(int i=1;cnt-i+1>n/2;i++,lt=i){
			if(p==0){
				if(g[f[p][i]][1]>g[f[p][i]][2])f[1][++lb]=f[p][i];
				else f[2][++lc]=f[p][i];
			}else if(p==1){
				if(g[f[p][i]][0]>g[f[p][i]][2])f[0][++la]=f[p][i];
				else f[2][++lc]=f[p][i];
			}else{
				if(g[f[p][i]][0]>g[f[p][i]][1])f[0][++la]=f[p][i];
				else f[1][++lb]=f[p][i];
			}
		}
		int fa=1,fb=1,fc=1;
		if(p==0)fa=lt;
		else if(p==1)fb=lt;
		else fc=lt;
		for(int i=fa;i<=la;i++){
			ans+=g[f[0][i]][0];
		}
		for(int i=fb;i<=lb;i++){
			ans+=g[f[1][i]][1];
		}
		for(int i=fc;i<=lc;i++){
			ans+=g[f[2][i]][2];
		}
		printf("%lld\n",ans);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
