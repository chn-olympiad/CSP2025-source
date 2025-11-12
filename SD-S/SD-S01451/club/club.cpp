#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int t,n,scd,vis[1000001],itr[100001];
long long a[100001][5],ans,cnt[11],ast[100001][5];
priority_queue<pair<long long,pair<int,int> > >q;
priority_queue<pair<long long,pair<int,int> > >q2[5];
void dfs(int k,long long s){
	if(k>n){
		ans=max(ans,s);
		return;
	}
	if(cnt[1]<n/2){
		cnt[1]++;
		dfs(k+1,s+a[k][1]);
		cnt[1]--;
	}
	if(cnt[2]<n/2){
		cnt[2]++;
		dfs(k+1,s+a[k][2]);
		cnt[2]--;
	}
	if(cnt[3]<n/2){
		cnt[3]++;
		dfs(k+1,s+a[k][3]);
		cnt[3]--;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		while(!q.empty())q.pop();
		while(!q2[1].empty())q2[1].pop();
		while(!q2[2].empty())q2[2].pop();
		while(!q2[3].empty())q2[3].pop();
		ans=0;
		scd=0;
		for(int i=1; i<=n; i++) {
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
			vis[i]=0;
			itr[i]=0;
			ast[i][1]=0;
			ast[i][2]=0;
			ast[i][3]=0;
		}
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]) {
				if(a[i][1]>=a[i][3]) {
					ast[i][1]=1;
					if(a[i][3]>=a[i][2]) {
						ast[i][2]=3;
						ast[i][3]=2;
					} else {
						ast[i][2]=2;
						ast[i][3]=3;
					}
				} else {
					ast[i][1]=3;
					ast[i][2]=1;
					ast[i][3]=2;
				}
			} else {
				if(a[i][2]>=a[i][3]) {
					ast[i][1]=2;
					if(a[i][3]>=a[i][1]) {
						ast[i][2]=3;
						ast[i][3]=1;
					} else {
						ast[i][2]=1;
						ast[i][3]=3;
					}
				} else {
					ast[i][1]=3;
					ast[i][2]=2;
					ast[i][3]=1;
				}
			}
			q.push(make_pair(a[i][1],make_pair(i,1)));
			q.push(make_pair(a[i][2],make_pair(i,2)));
			q.push(make_pair(a[i][3],make_pair(i,3)));
		}
		if(n<=10) {
			cnt[1]=0;
			cnt[2]=0;
			cnt[3]=0;
			ans=0;
			dfs(1,0);
			printf("%lld\n",ans);
			continue;
		}
		while(!q.empty()) {
			pair<long long,pair<int,int> >tmp=q.top();
			q.pop();
			itr[tmp.second.first]++;
			if(vis[tmp.second.first])continue;
			if(cnt[tmp.second.second]<n/2) {
				ans+=tmp.first;
				vis[tmp.second.first]=1;
				cnt[tmp.second.second]++;
				if(itr[tmp.second.first]<3) {
					q2[tmp.second.second].push(make_pair(a[tmp.second.first][ast[tmp.second.first][itr[tmp.second.first]+1]]-tmp.first,make_pair(tmp.second.first,ast[tmp.second.first][itr[tmp.second.first]+1])));
				}
			} else {
				if(q2[tmp.second.second].size()) {
					pair<long long,pair<int,int> >tmp2=q2[tmp.second.second].top();
					long long k=tmp2.first;
					k+=tmp.first-a[tmp.second.first][ast[tmp.second.first][itr[tmp.second.first]+1]];
//				cout<<tmp2.first<<" "<<tmp.first<<" "<<k<<"<<"<<endl;
					if(k>0) {
						vis[tmp.second.first]=1;
						cnt[tmp2.second.second]++;
						ans+=tmp2.first+tmp.first;
						q2[tmp.second.second].pop();
						if(itr[tmp.second.first]<3) {
							q2[tmp.second.second].push(make_pair(a[tmp.second.first][ast[tmp.second.first][itr[tmp.second.first]+1]]-tmp.first,make_pair(tmp.second.first,ast[tmp.second.first][itr[tmp.second.first]+1])));
						}
						itr[tmp2.first]++;
						if(itr[tmp2.second.first]<3) {
							q2[tmp2.second.second].push(make_pair(a[tmp2.second.first][ast[tmp2.second.first][itr[tmp2.second.first]+1]]-a[tmp2.second.first][ast[tmp2.second.first][itr[tmp2.second.first]]],make_pair(tmp.second.first,ast[tmp.second.first][itr[tmp.second.first]+1])));
						}
					} else {
						continue;
					}
				} else {
					continue;
				}
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}
