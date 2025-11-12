#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;
}
const int N=1e5+5;
int t,n,ans,a[N][3],m,b[N],res,cnt[3];
pair<int,int> p[N];
bool A,B;
struct DP{
	int x,y,z,v;
}dp[N][3];
inline void dfs(int x,int y){
	if(x>n){
		res=max(res,y);
		return;
	}
	for(int i=0;i<3;++i) if(cnt[i]<m){
		++cnt[i];
		dfs(x+1,y+a[x][i]);
		--cnt[i];
	}
}
inline bool cmp(pair<int,int> x,pair<int,int> y){return x.first>y.first;}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read(),m=n>>1,ans=0,A=B=1;
		for(int i=1,x;i<=n;++i){
			a[i][0]=read(),a[i][1]=read(),a[i][2]=read(),x=min(a[i][0],min(a[i][1],a[i][2])),ans+=x,a[i][0]-=x,a[i][1]-=x,a[i][2]-=x;
			if(a[i][1]>0) A=0;
			if(a[i][2]>0) B=0;
		}
		if(A&&B){
			for(int i=1;i<=n;++i) b[i]=a[i][0];
			sort(b+1,b+1+n);
			for(int i=n/2+1;i<=n;++i) ans+=b[i];
			cout<<ans<<'\n';
		}else if(B){
			for(int i=1;i<=n;++i)
				if(a[i][0]<a[i][1]) ans+=a[i][0],p[i]={a[i][1]-a[i][0],1};
				else ans+=a[i][1],p[i]={a[i][0]-a[i][1],0};
			sort(p+1,p+1+n,cmp);
			cnt[0]=cnt[1]=0;
			for(int i=1;i<=n;++i) if(cnt[p[i].second]<m) ++cnt[p[i].second],ans+=p[i].first;
			cout<<ans<<'\n';
		}else if(n<=15){
			res=cnt[0]=cnt[1]=cnt[2]=0;
			dfs(1,0);
			cout<<res+ans<<'\n';
		}else{
			//dp[1][0].x=dp[1][1].y=dp[1][2].z=1,dp[1][0].y=dp[1][0].z=dp[1][1].x=dp[1][1].z=dp[1][2].x=dp[1][2].y=0,
			//dp[1][0].v=a[1][0],dp[1][1].v=a[1][1],dp[1][2].v=a[1][2];
			dp[1][0]={1,0,0,a[1][0]},dp[1][1]={0,1,0,a[1][1]},dp[1][2]={0,0,1,a[1][2]};
			for(int i=2,j;i<=n;++i){
				dp[i][0].v=dp[i][1].v=dp[i][2].v=-1;
				for(j=1;j<i;++j){
					if(dp[j][0].x<m&&dp[j][0].v+a[i][0]>dp[i][0].v)
						dp[i][0]={dp[j][0].x+1,dp[j][0].y,dp[j][0].z,dp[j][0].v+a[i][0]};
					if(dp[j][1].x<m&&dp[j][1].v+a[i][0]>dp[i][0].v)
						dp[i][0]={dp[j][1].x+1,dp[j][1].y,dp[j][1].z,dp[j][1].v+a[i][0]};
					if(dp[j][2].x<m&&dp[j][2].v+a[i][0]>dp[i][0].v)
						dp[i][0]={dp[j][2].x+1,dp[j][2].y,dp[j][2].z,dp[j][2].v+a[i][0]};
						
					if(dp[j][0].y<m&&dp[j][0].v+a[i][1]>dp[i][1].v)
						dp[i][1]={dp[j][0].x,dp[j][0].y+1,dp[j][0].z,dp[j][0].v+a[i][1]};
					if(dp[j][1].y<m&&dp[j][1].v+a[i][1]>dp[i][1].v)
						dp[i][1]={dp[j][1].x,dp[j][1].y+1,dp[j][1].z,dp[j][1].v+a[i][1]};
					if(dp[j][2].y<m&&dp[j][2].v+a[i][1]>dp[i][1].v)
						dp[i][1]={dp[j][2].x,dp[j][2].y+1,dp[j][2].z,dp[j][2].v+a[i][1]};
						
					if(dp[j][0].z<m&&dp[j][0].v+a[i][2]>dp[i][2].v)
						dp[i][2]={dp[j][0].x,dp[j][0].y,dp[j][0].z+1,dp[j][0].v+a[i][2]};
					if(dp[j][1].z<m&&dp[j][1].v+a[i][2]>dp[i][2].v)
						dp[i][2]={dp[j][1].x,dp[j][1].y,dp[j][1].z+1,dp[j][1].v+a[i][2]};
					if(dp[j][2].z<m&&dp[j][2].v+a[i][2]>dp[i][2].v)
						dp[i][2]={dp[j][2].x,dp[j][2].y,dp[j][2].z+1,dp[j][2].v+a[i][2]};
				}
			}
			cout<<max(dp[n][0].v,max(dp[n][1].v,dp[n][2].v))+ans<<'\n';
		}
	}
	return 0;
}//Ren5Jie4Di4Ling5%
