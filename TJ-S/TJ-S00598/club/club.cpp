#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cassert>
const int N=100005;
int T,n;
int a[N][5];
namespace Force{
	long long qpow(long long x,int y){
		long long ans=1;
		for(;y;y>>=1,x=x*x){
			if(y&1) ans*=x;
		}
		return ans;
	}
	int cnt[5];
	void solve(){
		int ans=0;
		for(int s=0;s<qpow(3,n);s++){
			for(int i=1;i<=3;i++){
				cnt[i]=0;
			}
			int st=s,sum=0;
			bool ok=true;
			for(int i=1;i<=n;i++){
				if(++cnt[st%3+1]>(n/2)) ok=false;;
				sum+=a[i][st%3+1];
				st/=3;
			}
			if(ok) ans=std::max(ans,sum);
		}
		printf("%d\n",ans);
	}
}
namespace Better{
	const int M=205;
	bool hm[M][M][M];
	int me[M][M][M];
	int dfs(int x,int f1,int f2){
		if(x>n) return (f1*2<=n&&f2*2<=n&&(n-f1-f2)*2<=n)?0:-0x3f3f3f3f;
		if(hm[x][f1][f2]) return me[x][f1][f2];
		int ans=-0x3f3f3f3f;
		ans=std::max(ans,dfs(x+1,f1+1,f2)+a[x][1]);
		ans=std::max(ans,dfs(x+1,f1,f2+1)+a[x][2]);
		ans=std::max(ans,dfs(x+1,f1,f2)+a[x][3]);
		hm[x][f1][f2]=true;
		return me[x][f1][f2]=ans;
	}
	void solve(){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					hm[i][j][k]=false;
				}
			}
		}
		printf("%d\n",dfs(1,0,0));
	}
}
namespace Better1{
	struct rec{
		int x[5];
	}b[N];
	bool cmp1(const rec &a,const rec &b){
		return std::max(a.x[2],a.x[3])-a.x[1]>std::max(b.x[2],b.x[3])-b.x[1];
	}
	bool cmp2(const rec &a,const rec &b){
		return std::max(a.x[3],a.x[1])-a.x[2]>std::max(b.x[3],b.x[1])-b.x[2];
	}
	bool cmp3(const rec &a,const rec &b){
		return std::max(a.x[1],a.x[2])-a.x[3]>std::max(b.x[1],b.x[2])-b.x[3];
	}
	void solve(){
		for(int i=1;i<=n;i++){
			b[i].x[1]=a[i][1],b[i].x[2]=a[i][2],b[i].x[3]=a[i][3];
		}
		int ans=0;
		for(int d=1;d<=3;d++){
			int sum=0;
			for(int i=1;i<=n;i++) sum+=a[i][d];
			if(d==1) std::sort(b+1,b+n+1,cmp1);
			else if(d==2) std::sort(b+1,b+n+1,cmp2);
			else if(d==3) std::sort(b+1,b+n+1,cmp3);
			else assert(false);
			int cnt1=0,cnt2=0;
			for(int i=1;i<=n&&(i<=n/2||std::max(b[i].x[d%3+1],b[i].x[((d%3+1)%3)+1])-b[i].x[d]>0);i++){
				//printf("%d %d %d %d\n",d,b[i].x[d],b[i].x[d%3+1],b[i].x[((d%3+1)%3)+1]);
				if(b[i].x[d%3+1]>b[i].x[((d%3+1)%3)+1]){
					if(cnt1<n/2){
						sum+=std::max(b[i].x[d%3+1],b[i].x[((d%3+1)%3)+1])-b[i].x[d];
						cnt1++;
					}else{
						if(cnt2<n/2&&(std::min(b[i].x[d%3+1],b[i].x[((d%3+1)%3)+1])-b[i].x[d]>0)){
							sum+=std::min(b[i].x[d%3+1],b[i].x[((d%3+1)%3)+1])-b[i].x[d];
							cnt2++;
						}
					}
				}else{
					if(cnt2<n/2){
						sum+=std::max(b[i].x[d%3+1],b[i].x[((d%3+1)%3)+1])-b[i].x[d];
						cnt2++;
					}else{
						if(cnt1<n/2&&(std::min(b[i].x[d%3+1],b[i].x[((d%3+1)%3)+1])-b[i].x[d]>0)){
							sum+=std::min(b[i].x[d%3+1],b[i].x[((d%3+1)%3)+1])-b[i].x[d];
							cnt1++;
						}
					}
				}
			}
			ans=std::max(ans,sum);
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		//Force::solve();
		Better1::solve();
	}
	return 0;
}
