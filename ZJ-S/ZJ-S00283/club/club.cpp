#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+5;
int T,n,a,b,c;
vector<int> G[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ll ans=0;
		for(int i=1;i<=3;i++) G[i].clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(a>=b&&a>=c)
				G[1].push_back(min(a-b,a-c));
			else if(b>=a&&b>=c)
				G[2].push_back(min(b-a,b-c));
			else
				G[3].push_back(min(c-a,c-b));
			ans+=max(a,max(b,c));
		}
		if(G[2].size()>n/2) swap(G[1],G[2]);
		if(G[3].size()>n/2) swap(G[1],G[3]);
		if(G[1].size()>n/2){
			sort(G[1].begin(),G[1].end());
			for(int i=0;i<G[1].size();i++){
				ans-=G[1][i];
				if(G[1].size()-n/2==i+1) break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
