#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FORG(i,u) for(int i=head[u];~i;i=nxt[i])
ll mat[4][N];
int a[N][4];
int cnt[4];
int cntf;
int fmat[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		FOR(i,1,3)cnt[i]=0;
		cntf=0;
		int n;cin>>n;
		ll ans=0;
		FOR(i,1,n){
			int num=0,mmax=0;
			FOR(j,1,3){
				cin>>a[i][j];
				if(mmax<a[i][j])mmax=a[i][j],num=j;
			}
			ans+=mmax;
			mat[num][++cnt[num]]=i;
		}
		int maxnum=0;
		FOR(i,1,3){
			if(cnt[i]>n/2){
				maxnum=i;
			}
		}
		if(!maxnum){
			cout<<ans<<"\n";
			continue;
		}
		FOR(i,1,cnt[maxnum]){
			fmat[++cntf]=INT_MAX;
			FOR(j,1,3){
				if(j==maxnum)continue;
				int now=mat[maxnum][i];
				fmat[cntf]=min(fmat[cntf],a[now][maxnum]-a[now][j]);
			}
		}
		sort(fmat+1,fmat+cntf+1);
		FOR(i,1,cntf-n/2){
			ans-=fmat[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
