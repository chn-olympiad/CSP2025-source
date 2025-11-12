#include<bits/stdc++.h>
using namespace std ;
const int N=210 ;
#define ll long long
ll n , s , t , sor[N][3] , cho[3] ;
ll r[N][N/2][N/2][N/2] ;
bool vis[N] ;
ll dfs( int d ) {
	if ( d==n+1 ) {
		return 0 ;
	}
	if ( r[d][cho[0]][cho[1]][cho[2]]!=-1 ) {
		return r[d][cho[0]][cho[1]][cho[2]] ;
	}
	ll ans=0 ;
	for ( int i=0 ; i<3 ; i++ ) {
		if ( cho[i]<n/2 ) {
			cho[i]++ ;
			ans=max(ans,sor[d][i]+dfs(d+1)) ;
			cho[i]-- ;
		}
	}
	return (r[d][cho[0]][cho[1]][cho[2]]=ans) ;
}
int main() {
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	scanf("%d",&t) ;
	while ( t-- ) {
		memset(cho,0,sizeof(cho)) ;
		memset(r,-1,sizeof(r)) ;
		scanf("%d",&n) ;
		for ( int i=1 ; i<=n ; i++ ) {
			for ( int j=0 ; j<3 ; j++ ) {
				scanf("%d",&sor[i][j]) ;
			} 
		}
		printf("%d\n",dfs(1)) ;
	} 
	return 0 ;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/ 