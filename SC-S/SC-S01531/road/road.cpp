/*
记住，freopen前不可以读入！


*/
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define ls (id<<1)
#define rs (id<<1|1)
inline int read(){
	int sum=0,k=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){sum=sum*10+c-48;c=getchar();}
	return sum*k;
}
using namespace std;
const int M=1e6+110;

struct Node{
	int u,v,w;
	inline operator >(const Node &x)const{
		return w>x.w;
	}
}x,a[M];
priority_queue<Node,vector<Node>,greater<Node>>q;
int n,m,k,fa[M],num,qf[20][10015],c[20],ans=0,sz[M];
inline int fid(int x){
	if(fa[x]==x) return x;
	return fa[x]=fid(fa[x]);
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		x.u=read(),x.v=read(),x.w=read();
		q.push(x);
	}
	while(!q.empty()){
		x=q.top();q.pop();
		if(num==n-1) continue;
		int A=fid(x.u),B=fid(x.v);
		if(A==B) continue;
//		if(sz[A]>sz[B]) sz[A]+=sz[B],fa[B]=A;
//		else fa[A]=B,sz[B]+=sz[A];
		fa[A]=B;
		a[++num]=x;
		ans+=x.w;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) qf[i][j]=read();
	}
	for(int s=1;s<=((1<<k)-1);s++){
		int res=0,qaq=n;
		for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
		for(int i=1;i<=n-1;i++) q.push(a[i]);
		for(int i=1;i<=k;i++){
			if((s)&(1<<(i-1))){
				res+=c[i];
				qaq++;
				for(int j=1;j<=n;j++){
					x.u=qaq;x.v=j;
					x.w=qf[i][j];
					q.push(x);
				}
			}
		}
		num=0;
		while(!q.empty()){	
			x=q.top();q.pop();
			if(num==qaq-1) continue;
			int A=fid(x.u),B=fid(x.v);
			if(A==B) continue;
//			if(sz[A]>sz[B]) sz[A]+=sz[B],fa[B]=A;
//			else fa[A]=B,sz[B]+=sz[A];
			fa[A]=B;
			res+=x.w;
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
你发现村庄的数量很少
考虑做状压
每次提前加上村庄的花费
并查集作最小生成树
*/