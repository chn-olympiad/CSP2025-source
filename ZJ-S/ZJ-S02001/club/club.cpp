#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0; bool f=0; char ch=getchar();
	for( ; ch<'0' || ch>'9' ; ch=getchar() ) ( ch=='-' ) && ( f=1 );
	for( ; ch>='0' && ch<='9' ; ch=getchar() ) x=(x<<3)+(x<<1)+(ch^'0');
	return f ? -x : x;
}
struct Node{
	long long next,x,la,lc;
	bool operator<( const Node &p ) const{
		return x>p.x;
	}
};
struct data{
	long long id,x;
	
}a[100005][5];
bool cmp( data a,data b ){
	return a.x>b.x;
}
long long T,n,m,cnt[5],ans;
priority_queue<Node> q[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	for( ; T-- ; ){
		n=read();
		m=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j].id=j;
				a[i][j].x=read();
			}
			sort( a[i]+1,a[i]+3+1,cmp );
			if( cnt[ a[i][1].id ]<m ){
				cnt[ a[i][1].id ]++;
				ans+=a[i][1].x;
				q[ a[i][1].id ].push( Node{ a[i][2].id,a[i][1].x-a[i][2].x,a[i][3].id,a[i][2].x-a[i][3].x } );
			}				
			else{
				if( a[i][2].x > a[i][1].x-q[ a[i][1].id ].top().x ){
					cnt[ a[i][2].id ]++;
					ans+=a[i][2].x;
					q[ a[i][2].id ].push( Node{ a[i][3].id,a[i][2].x-a[i][3].x,-1,1e9 } );
				}
				else{
					ans+=( a[i][1].x-q[ a[i][1].id ].top().x );
					cnt[ q[ a[i][1].id ].top().next ]++;
					q[ q[ a[i][1].id ].top().next ].push( Node{ q[ a[i][1].id ].top().la,q[ a[i][1].id ].top().lc,-1,1e9 } );
					q[ a[i][1].id ].pop();
					cnt[ a[i][1].id ]++;
					q[ a[i][1].id ].push( Node{ a[i][2].id,a[i][1].x-a[i][2].x,a[i][3].id,a[i][2].x-a[i][3].x } );
				}
			}
		}
		cout<<ans<<'\n';
		ans=0;
		for(int j=1;j<=3;j++) for( ; !q[j].empty() ; q[j].pop() );
		for(int j=1;j<=3;j++) cnt[j]=0;
	}
	return 0;
}
