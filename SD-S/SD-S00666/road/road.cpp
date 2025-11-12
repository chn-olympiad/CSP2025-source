#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,k,ans;
int fa[1010];
int finda(int x){
	if(fa[x]==x) return x;
	fa[x]=finda(fa[x]);
	return fa[x];
}
void ds(int a,int b){
	fa[finda(a)]=fa[finda(b)];
}
struct node{
	int u,v,w;
};
node a[1000010];
bool cmd(node x,node y){
	return x.w<y.w;
} 
bool jd[1010];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
	}
	sort(a+1,a+1+n,cmd);
	int l=0,i=0;
	int cj;
	if(k>0) cj=read();
	if(cj==0){
		cout<<0;
		return 0;
	}
	while(l!=n){
		i++;
		if(jd[a[i].u]&&jd[a[i].v]){
			
		}else{
			ds(a[i].u,a[i].v);
			ans+=a[i].w;
			if(!jd[a[i].u]){
				jd[a[i].u]=1;
				l++;
			}
			if(!jd[a[i].v]){
				jd[a[i].v]=1;
				l++;
			} 
		}
	}
	cout<<ans;
	return 0;
} 
//csp-2025 rp++!
//SD-S00666
//Èü²©·ð×æ±£ÓÓ 
