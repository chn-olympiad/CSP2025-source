#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<' '<<x<<'\n'
#define int long long
const int N=1e5+5;
int n;
struct node{
	int s,n1,n2,n3;
}f[N][5];
struct eee{
	int a,b,c,d;
}a[N];
bool cmp(eee a,eee b){
	if(a.a>b.a)return 1;
	if(a.a==b.a){
		if(a.b>b.b){
			return 1;
		}
		if(a.c>b.c){
			return 1;
		}
		return 0;
	}
	return 0;
}
int mb[300],ans;
void dfs(int i,int sum,int x,int y,int z){
	if(x*2>n||y*2>n||z*2>n)return ;
	if(i==n+1){
		ans=max(sum,ans);
		return ;
	}
	dfs(i+1,sum+a[i].a,x+1,y,z);
	dfs(i+1,sum+a[i].b,x,y+1,z);
	dfs(i+1,sum+a[i].c,x,y,z+1);
}
int p[40],vis[40];
void DFS(int ii){
	if(ii*2==n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				sum+=max(a[i].b,a[i].c);
			}else{
				sum+=max(a[i].a,a[i].c);
			}
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		DFS(ii+1);
		vis[i]=0;
	}
}
void work(){
	memset(f,0,sizeof f);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].a);
		scanf("%lld",&a[i].b);
		scanf("%lld",&a[i].c);		
	}  
	sort(a+1,a+n+1,cmp);
	if(n<=10){
		ans=0;
		dfs(0,0,0,0,0);
		cout<<ans<<'\n';
		return ;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=3;j++){
			if(f[i-1][j].n1+1<=n/2){
				if(f[i-1][j].s+a[i].a>=f[i][1].s){
					f[i][1].s=f[i-1][j].s+a[i].a;
					f[i][1].n1=f[i-1][j].n1+1;
					f[i][1].n2=f[i-1][j].n2;
					f[i][1].n3=f[i-1][j].n3;
//					debug(f[1][1].n1);
				}
			}
			
			if(f[i-1][j].n2+1<=n/2){
				if(f[i-1][j].s+a[i].b>=f[i][2].s){
					f[i][2].s=f[i-1][j].s+a[i].b;
					f[i][2].n1=f[i-1][j].n1;
					f[i][2].n2=f[i-1][j].n2+1;
					f[i][2].n3=f[i-1][j].n3;
				}
			}
			
			if(f[i-1][j].n3+1<=n/2){
				if(f[i-1][j].s+a[i].c>=f[i][3].s){
					f[i][3].s=f[i-1][j].s+a[i].c;
					f[i][3].n1=f[i-1][j].n1;
					f[i][3].n2=f[i-1][j].n2;
					f[i][3].n3=f[i-1][j].n3+1;
				}
			}
		}
//		debug(f[1][1].n1);debug(f[1][2].n1);debug(f[1][3].n1);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++){
//			cout<<f[i][j].s<<' ';
//			
//		}cout<<'\n';
//	} 
	int ans=max(f[n][1].s,max(f[n][2].s,f[n][3].s));
	printf("%lld\n",ans);
}
bool cmpp(eee a,eee b){
	return a.d>b.d;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--)work(); 
	return 0;
} 
