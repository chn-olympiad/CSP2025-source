#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e6+10;
int T,n,m,k;
int e[N],ne[N],h[N],w[N],idx=0;
int dis[N],v[N];
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
void write(int n){
	if(n<0){
		n=-n;
		putchar('-');
	}
	if(n>=10){
		write(n/10);
	}
	putchar(n%10+'0');
}
void add(int a,int b,int c){
	e[++idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx;
}
void diji(){
	memset(dis,0x7f,sizeof dis);
	memset(v,0,sizeof v);
	priority_queue< pair<int,int> > q;
	dis[1]=0;
	q.push(make_pair(0,1));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(v[u]) continue;
		v[u]=1;
		for(int i=h[u];~i;i=ne[i]){
			int d=e[i],l=w[i];
			if(dis[d]>dis[u]+l){
				dis[d]=dis[u]+l;
				q.push(make_pair(-dis[d],d));
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dis[i];
//		cout<<ds[i]<<'\n'; 
	}
	write(ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h,-1,sizeof h);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		int a,b,c;
		a=read(),b=read(),c=read();
		add(a,b,c);
		add(b,a,c);
	}
	
	for(int i=1;i<=k;i++){
		int a;
		a=read();
		for(int j=1;j<=n;j++){
			int b;
			b=read();
			add(n+i+1,j,b);
			add(j,n+i,a+b);
		}
	}
	diji();
	return 0;
}

