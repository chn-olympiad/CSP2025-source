#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,a[10],vis[101000],sum[10],ans,ma,cma,mai,cmai;
priority_queue<pair<pair<ll,ll>,pair<ll,pair<ll,ll> > > >q;
priority_queue<ll>qk[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			ma=-1,mai=-1;
			cma=-1,cmai=-1;
			for(int j=1;j<=3;j++){
				cin>>a[j];
				if(a[j]>ma) ma=a[j],mai=j; 
			}
			for(int j=1;j<=3;j++) if(j!=mai) if(a[j]>cma) cma=a[j],cmai=j; 
			q.push(make_pair(make_pair(ma,cma),make_pair(i,make_pair(mai,cmai))));
		}
		ans=sum[1]=sum[2]=sum[3]=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++){
			pair<pair<ll,ll>,pair<ll,pair<ll,ll> > >X=q.top();q.pop();
			if(vis[X.second.first]) continue;
			if(sum[X.second.second.first]==n/2){
				if(-qk[X.second.second.first].top()<X.first.first-X.first.second) ans+=qk[X.second.second.first].top(),ans+=X.first.first,qk[X.second.second.first].pop(),qk[X.second.second.first].push(-(X.first.first-X.first.second));
				else{
					vis[X.second.first]=1,sum[X.second.second.second]++;
					ans+=X.first.second;
				}
			}
			else{
				vis[X.second.first]=1,sum[X.second.second.first]++;
				ans+=X.first.first;
				qk[X.second.second.first].push(-(X.first.first-X.first.second));
			}
		}
		while(!qk[1].empty()) qk[1].pop();
		while(!qk[2].empty()) qk[2].pop();
		while(!qk[3].empty()) qk[3].pop();
		cout<<ans<<'\n';
	}
	return 0;
}