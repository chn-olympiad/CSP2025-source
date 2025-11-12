#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][5],cnt[5],grp[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++){
			int mx=-1;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>mx) mx=a[i][j],grp[i]=j;
			}
			ans+=mx,cnt[grp[i]]++;
		}
		int p=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2) p=i;
		}
		if(p){
			priority_queue<pair<int,int>> pq;
			for(int i=1;i<=n;i++){
				if(grp[i]!=p) continue;
				for(int j=1;j<=3;j++){
					if(j==p) continue;
					pq.push({a[i][j]-a[i][p],i});
				}
			}
			while(cnt[p]>n/2){
				int x=pq.top().first,y=pq.top().second;
				pq.pop();
				if(grp[y]!=p) continue;
				ans+=x,grp[y]=0,cnt[p]--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
