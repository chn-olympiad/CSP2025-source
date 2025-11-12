#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n,a[N][3];
int dp[510][510],ans,bf[N],cn_t,tj,bl,cc[3];
bitset<N> pd;
bool tp1;
struct nod1{
	int sy,va,lx;
	bool operator<(const nod1 &mfmf)const{
		return va>mfmf.va;
	}
}sr[N*3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	for(int TT=1;TT<=T;++TT){
		ans=0;
		tp1=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]!=0||a[i][2]!=0) tp1=1;
		}
		if(n<=500){
			for(int i=1;i<=n;++i){
				for(int j=n/2;j>=0;--j){
					for(int z=n/2;z>=0;--z){
						if(j+z>i) continue;
						if(j+z<i)dp[j][z]+=a[i][2];
						if(j>=1){
							dp[j][z]=max(dp[j][z],dp[j-1][z]+a[i][0]);
						}
						if(z>=1){
							dp[j][z]=max(dp[j][z],dp[j][z-1]+a[i][1]);
						}
						if(n-z-j<=n/2) ans=max(ans,dp[j][z]);
					}
				}
			}
			cout<<ans<<'\n';
			memset(dp,0,sizeof(dp));	
		}
		else{
			if(!tp1){
				for(int i=1;i<=n;++i){
					bf[i]=a[i][0];
				}
				sort(bf+1,bf+n+1);
				for(int i=n;i>n/2;--i){
					ans+=bf[i];
				}
				cout<<ans<<'\n';
			}
			else{
				memset(sr,0,sizeof(sr));
				cn_t=0;
				memset(cc,0,sizeof(cc));
				pd.reset();
				for(int i=1;i<=n;++i){
					sr[++cn_t].sy=i,sr[cn_t].va=a[i][0],sr[cn_t].lx=0;
					sr[++cn_t].sy=i,sr[cn_t].va=a[i][1],sr[cn_t].lx=1;
					sr[++cn_t].sy=i,sr[cn_t].va=a[i][2],sr[cn_t].lx=2;
				} 
				sort(sr+1,sr+cn_t+1);
				tj=0;
				bl=1;
				while(tj<n){
					if(!pd[sr[bl].sy]&&cc[sr[bl].lx]+1<=n/2){
						ans+=sr[bl].va;
						++tj;
						++cc[sr[bl].lx];
						pd[sr[bl].sy]=1;
					}
					++bl;
				}
				cout<<ans<<'\n';
			}
		}
		for(int i=0;i<=n;++i){
			a[i][0]=a[i][1]=a[i][2]=0;
		}
	}
	return 0;
}

