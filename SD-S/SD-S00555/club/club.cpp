#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int N=1e5+10;

int T;//¶à²âÇå¿Õ£¡£¡£¡ 
int n;
int zn[4];
long long a[N][4];

priority_queue<long long> fh[4];

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	
	while(T--){
		scanf("%d",&n);
		
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				scanf("%lld",&a[i][j]);
			}
		}
		
		for(int i=1;i<=3;++i){
			zn[i]=0;
			while(!fh[i].empty()){
				fh[i].pop();
			}
		}
		
		
		int maxn;
		long long ans=0;
		long long maxx;
		for(int i=1;i<=n;++i){
			maxn=0;
			maxx=-0x3f3f3f3f3f3f3f3f;
			a[i][0]=-1;
			
			for(int j=1;j<=3;++j){
				if(a[i][j]>a[i][maxn]){
					maxn=j;
				}
			}
			
			for(int j=1;j<=3;++j){
				if(j==maxn) continue;
				maxx=max(maxx,a[i][j]-a[i][maxn]);
			}
			fh[maxn].push(maxx);
			
			if(zn[maxn]==(n>>1)){
				ans+=a[i][maxn];
				ans+=fh[maxn].top();
				fh[maxn].pop();
			}
			else{
				++zn[maxn];
				ans+=a[i][maxn];
			}
			
		}
		
		printf("%lld\n",ans);
		
	}
	
	return 0;
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

Iloveyou
Iloveyou
Iloveyou
QAQ
Really!
Staywithme

*/
