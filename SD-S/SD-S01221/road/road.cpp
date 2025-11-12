#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
}a[1500010];
int n,m,k,tot,fa[10050],c[20],ans;
void add(int u,int v,int w){
	a[++tot].u=u;
	a[tot].v=v;
	a[tot].w=w;
}
bool cmp(node xx,node yy){
	return xx.w<yy.w;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int read(){
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int sum=0;
	while(c>='0'&&c<='9'){
		sum=(sum<<1)+(sum<<3)+(c-'0');
		c=getchar();
	}
	return sum;
}
void write(int res){
	if(res==0) return ;
	write(res/10);
	putchar(res%10+'0');
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		add(u,v,w);
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		flag+=(c[i]>0);
		for(int j=1;j<=n;j++){
			int w=read();
			flag+=(w>0);
			add(j,i+n,w);
		}
	}
	if(flag==0){
		putchar('0');
		return 0;
	}
	sort(a+1,a+tot+1,cmp);
	ans=0x3f3f3f3f3f3f3f3f;
	int zt=0,maxn=(1<<k)-1;
	while(zt<=maxn){
		int res=0;
		for(int i=0;i<k;i++) res+=((zt&(1<<i))>>i)*c[i+1];
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=tot;i++){
			if(a[i].v>n&&(zt&(1<<(a[i].v-n-1)))==0) continue;
			int x=find(a[i].u),y=find(a[i].v);
			if(x==y) continue;
			fa[x]=y;
			res+=a[i].w;
		}
		ans=min(ans,res);
		zt++;
	}
	write(ans);
	return 0;
}
