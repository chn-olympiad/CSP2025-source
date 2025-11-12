#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0; bool f=0; char ch=getchar();
	for( ; ch<'0' || ch>'9' ; ch=getchar() ) ( ch=='-' ) && ( f=1 );
	for( ; ch>='0' && ch<='9' ; ch=getchar() ) x=(x<<3)+(x<<1)+(ch^'0');
	return f ? -x : x;
}
struct node{
	long long to,c;
};
struct data{
	long long x,c;
	bool operator<( const data &p ) const{ return c>p.c; }
};
vector<node> a[1015];
priority_queue<data> q;
long long n,m,k,w[1005][1005],maxn[1005],d[15],p[15][1005],cnt,ans;
bool v[1015];
void bfs(){
	q.push( data{ 1,0 } );
	for( ; !q.empty() ; ){
		long long x=q.top().x;
		long long c=q.top().c;
		q.pop();
		if( v[x] ) continue;
		v[x]=1;
		ans+=c;
		if( x<=n ) cnt++;
		if( cnt==n ){
			cout<<ans;
			exit(0);
		}
		for(int i=0;i<a[x].size();i++){
			if( v[ a[x][i].to ] ) continue;
			q.push( data{ a[x][i].to,a[x][i].c } );
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(); m=read(); k=read();
	memset( w,0x7f,sizeof w );	
	for(int i=1;i<=m;i++){
		long long u=read(),v=read();
		w[u][v]=read();
		w[v][u]=w[u][v];
		maxn[u]=max( maxn[u],w[u][v] );
		maxn[v]=max( maxn[v],w[u][v] );
		a[u].push_back( node{ v,w[u][v] } );
		a[v].push_back( node{ u,w[u][v] } );
	}
	for(int i=1;i<=k;i++){
		d[i]=read();
		for(int j=1;j<=n;j++){
			p[i][j]=read();
			if( d[i]+p[i][j] > maxn[j] ) continue;
			for(int l=1;l<j;l++){
				if( d[i]+p[i][j]+p[i][l] < w[l][j] ){
					a[j].push_back( node{ l,d[i]+p[i][j]+p[i][l] } );
					a[l].push_back( node{ j,d[i]+p[i][j]+p[i][l] } );
				}
			}
		}
	}
	bfs();
	return 0;
}
