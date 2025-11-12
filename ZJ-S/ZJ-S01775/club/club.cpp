#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=1e17;
int T;
int n;
int a[200005][5];
int c[200005];
int to[200005];
int cnt[5];
priority_queue<int,vector<int>,greater<int> > pq;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>T;
	while(T--){
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)
			to[i]=0;
		while(!pq.empty())
			pq.pop();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			c[i]=inf;
			int t=1;
			for(int j=2;j<=3;j++)
				if(a[i][j]>a[i][t])
					t=j;
			cnt[t]++;to[i]=t;
			for(int j=1;j<=3;j++){
				if(t==j) continue;
				c[i]=min(c[i],abs(a[i][t]-a[i][j]));
			}
		}
		int t=0;
		for(int i=1;i<=3;i++)
			if(cnt[i]>(n+1)/2)
				t=i;
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=a[i][to[i]];
//		cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<' '<<t<<'\n';
//		for(int i=1;i<=n;i++)
//			cout<<to[i]<<' ';
//		cout<<'\n';
		if(t){
			for(int i=1;i<=n;i++)
				if(to[i]==t)
					pq.push(c[i]);
			while(cnt[t]>(n+1)/2){
				int x=pq.top();
				pq.pop();
				ans-=x;
				cnt[t]--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
