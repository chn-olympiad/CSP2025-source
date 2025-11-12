#include<cstdio>
#include<algorithm>
#include<cmath>
/*
namespace force{
	int T;
	int n;
	const int MAXN=1e5+5;
	const int INF=0x3f3f3f3f;
	int a[MAXN];
	int b[MAXN];
	int c[MAXN];
	int num[5];
	int ans=-INF;
	int now=0;
	int f[MAXN];
	void dfs(){
		if(now==n){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(f[i]==1) sum+=a[i];
				if(f[i]==2) sum+=b[i];
				if(f[i]==3) sum+=c[i];
			}
			ans=std::max(sum,ans);
			return;
		}
		for(int i=1;i<=3;i++){
			if(num[i]<n/2){
				num[i]++;
				f[++now]=i;
				dfs();
				f[now--]=0;
				num[i]--;
			}
		}
	}
	void solve(){
		freopen("club.in","r",stdin);
		scanf("%d",&T);
		while(T){
			T--;
			scanf("%d",&n);
			for(int i=1;i<=n;i++){
				scanf("%d %d %d",&a[i],&b[i],&c[i]);
			}
			dfs();
			printf("%d\n",ans);
			ans=-INF;
			for(int i=1;i<=3;i++)  num[i]=0;
		}
	}
}
namespace better{
	int T;
	int n;
	const int MAXN=1e5+5;
	const int INF=0x3f3f3f3f;
	int a[MAXN];
	int b[MAXN];
	int c[MAXN];
	int num[5];
	int ans=-INF;
	int now=1;
	int f[MAXN];
	int dfs(int now,int aa,int bb,int cc){
		if(now>n){
			return 0;
		}
		int ans=-INF;
		
		if(aa+1<=n/2) ans=std::max(ans,a[now]+dfs(now+1,aa+1,bb,cc));
		if(bb+1<=n/2) ans=std::max(ans,b[now]+dfs(now+1,aa,bb+1,cc));
		if(cc+1<=n/2) ans=std::max(ans,c[now]+dfs(now+1,aa,bb,cc+1));
		
		return ans;
	}
	void solve(){
		freopen("club.in","r",stdin);
		scanf("%d",&T);
		while(T){
			T--;
			scanf("%d",&n);
			for(int i=1;i<=n;i++){
				scanf("%d %d %d",&a[i],&b[i],&c[i]);
			}
			
			printf("%d\n",dfs(1,0,0,0));
		}
	}
}
*/
namespace best{
	int T;
	int n;
	const int MAXN=1e5+5;
	const int INF=0x3f3f3f3f;
	int a[MAXN];
	int b[MAXN];
	int c[MAXN];
	int num[5];
	int ans=-INF;
	int now=1;
	int f[MAXN];
	long long dfs(int now,int aa,int bb,int cc){
		if(now>n){
			return 0;
		}
		long long ans=-INF;
		
		if(aa+1<=n/2) ans=std::max(ans,a[now]+dfs(now+1,aa+1,bb,cc));
		if(bb+1<=n/2) ans=std::max(ans,b[now]+dfs(now+1,aa,bb+1,cc));
		if(cc+1<=n/2) ans=std::max(ans,c[now]+dfs(now+1,aa,bb,cc+1));
		
		return ans;
	}
	void solve(){

		scanf("%d",&T);
		while(T--){
			scanf("%d",&n);
			for(int i=1;i<=n;i++){
				scanf("%d %d %d",&a[i],&b[i],&c[i]);
			}
			printf("%lld\n",dfs(1,0,0,0));
		}
	}
}
/*
namespace favourite{
	int T;
	int n;
	const int MAXN=1e5+5;
	const int INF=0x3f3f3f3f;
	long long ans=0;
	int num[5];
	struct Hobbies{
		int a,b,c;
		int maxlove1;
		int maxlove2;
		int maxlove3;
		int loveid1;
		int loveid2;
		int loveid3;
	}son[MAXN];
	bool cmp(Hobbies a,Hobbies b){
		if(a.maxlove1!=b.maxlove1) return a.maxlove1>b.maxlove1;
		if(a.maxlove2!=b.maxlove2) return a.maxlove2>b.maxlove2;
		if(a.maxlove3!=b.maxlove3) return a.maxlove3>b.maxlove3;
		return false;
	}
	void solve(){
		scanf("%d",&T);
		while(T--){
			scanf("%d",&n);
			for(int i=1;i<=n;i++) {
				scanf("%d%d%d",&son[i].a,&son[i].b,&son[i].c);
				if(son[i].a>=son[i].b&&son[i].a>=son[i].c) son[i].loveid1=1,son[i].maxlove1=son[i].a;
				if(son[i].b>=son[i].a&&son[i].b>=son[i].c) son[i].loveid1=2,son[i].maxlove1=son[i].b;
				if(son[i].c>=son[i].a&&son[i].c>=son[i].b) son[i].loveid1=3,son[i].maxlove1=son[i].c;
				
				if(son[i].a<=son[i].b&&son[i].a>=son[i].c || son[i].a>=son[i].b&&son[i].a<=son[i].c) son[i].loveid2=1,son[i].maxlove2=son[i].a;
				if(son[i].b<=son[i].a&&son[i].b>=son[i].c || son[i].b>=son[i].a&&son[i].b<=son[i].c) son[i].loveid2=2,son[i].maxlove2=son[i].b;
				if(son[i].c<=son[i].a&&son[i].c>=son[i].b || son[i].c>=son[i].a&&son[i].c<=son[i].b) son[i].loveid2=3,son[i].maxlove2=son[i].c;
				
				if(son[i].a<=son[i].b&&son[i].a<=son[i].c) son[i].loveid3=1,son[i].maxlove3=son[i].a;
				if(son[i].b<=son[i].a&&son[i].b<=son[i].c) son[i].loveid3=2,son[i].maxlove3=son[i].b;
				if(son[i].c<=son[i].a&&son[i].c<=son[i].b) son[i].loveid3=3,son[i].maxlove3=son[i].c;
				
				if(son[i].maxlove1<son[i].maxlove2) std::swap(son[i].maxlove1,son[i].maxlove2),std::swap(son[i].loveid1,son[i].loveid2);
				if(son[i].maxlove1<son[i].maxlove3) std::swap(son[i].maxlove1,son[i].maxlove3),std::swap(son[i].loveid1,son[i].loveid3);
				if(son[i].maxlove2<son[i].maxlove3) std::swap(son[i].maxlove2,son[i].maxlove3),std::swap(son[i].loveid3,son[i].loveid2);
				
			}
			
			std::sort(&son[1],&son[n+1],cmp);
			
			
			
			for(int i=1;i<=n;i++){
				printf("i=%d %d %d %d 1=%d 2=%d 3=%d 1=%d 2=%d 3=%d\n",i,son[i].a,son[i].b,son[i].c,son[i].loveid1,son[i].loveid2,son[i].loveid3,son[i].maxlove1,son[i].maxlove2,son[i].loveid3);
			}
			
			
			
			
			for(int i=1;i<=n;i++){
				if(num[son[i].loveid1]+1<=n/2){
					num[son[i].loveid1]++;
					ans+=son[i].maxlove1;
				}
				else{
					if(num[son[i].loveid2]+1<=n/2){
						num[son[i].loveid2]++;
						ans+=son[i].maxlove2;
					}
					else{
						if(num[son[i].loveid3]+1<=n/2){
							num[son[i].loveid3]++;
							ans+=son[i].maxlove3;
						}
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
}
*/
int main(){
	/*
	force::solve();
	puts("");
	better::solve();
	puts("");
	*/		
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	best::solve();
	//favourite::solve();
	return 0;
}
