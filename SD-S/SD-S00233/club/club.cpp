#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n;
pair<int,int> a[100005][4];
priority_queue<pair<int,int>> pq[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j].first);
				a[i][j].second=j;
			}
			sort(a[i]+1,a[i]+3+1,greater<pair<int,int>>());
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(pq[a[i][1].second].size()<n/2)pq[a[i][1].second].push({-(a[i][1].first-a[i][2].first),-a[i][1].first});
			else{
				int tp=-pq[a[i][1].second].top().first,tp2=-pq[a[i][1].second].top().second;
				//cout<<i<<":"<<tp<<" "<<tp2<<"\n";
				if(a[i][1].first+tp2-tp>a[i][2].first+tp2){
					pq[a[i][1].second].pop();
					ans+=tp2-tp;
					pq[a[i][1].second].push({-(a[i][1].first-a[i][2].first),-a[i][1].first});
				}
				else{
					ans+=a[i][2].first;
				}
			}
		}
		for(int i=1;i<=3;i++){
			while(pq[i].size()){
				ans+=-(pq[i].top().second);
				pq[i].pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}//Love Chtholly forever
/*
1
2
10 9 8
4 0 0
*/
