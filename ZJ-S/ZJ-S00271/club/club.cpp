#include<bits/stdc++.h>
#define ci const int
#define ri register int
#define PII pair<int,int>
using namespace std;
ci N=1e5+5;
int t,n,maxn,tot[5],cntc[5],clu;
PII club[5][N];
long long ans;
bool inclub[N];
void dfs(int x,long long sum=0){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<3;++i){
		if(cntc[i]<maxn){
			cntc[i]++;
			dfs(x+1,sum+club[i][x].first);
			cntc[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	int x[5],maxa,id,cnt;
	while(t--){
		ans=0;
		scanf("%d",&n);
		maxn=n>>1;
		for(ri i=1;i<=n;++i){
			scanf("%d %d %d",&x[0],&x[1],&x[2]);
			club[0][i]={x[0],i};
			club[1][i]={x[1],i};
			club[2][i]={x[2],i};
		}
		if(n<=30){
			dfs(1);
			printf("%lld",ans);
			if(t) putchar('\n');
			continue;
		}
		memset(inclub,0,sizeof(inclub));
		memset(cntc,0,sizeof(cntc));
		sort(club[0]+1,club[0]+n+1);
		sort(club[1]+1,club[1]+n+1);
		sort(club[2]+1,club[2]+n+1);
		tot[0]=tot[1]=tot[2]=n;
		for(ri j=1;j<=n;++j){
			for(ri i=0;i<3;++i){
				while(tot[i]>=1&&inclub[club[i][tot[i]].second]){
					tot[i]--;
				}
			}
			maxa=0;
			cnt=0;
			for(ri i=0;i<3;++i){
				if(cntc[i]<maxn&&tot[i]>=1&&club[i][tot[i]].first>=maxa&&tot[i]>cnt){
					id=club[i][tot[i]].second;
					cnt=tot[i];
					clu=i;
					maxa=club[i][tot[i]].first;
				}
			}
			tot[clu]--;
			cntc[clu]++;
			ans+=maxa;
			inclub[id]=1;
		}
		printf("%lld",ans);
		if(t) putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}