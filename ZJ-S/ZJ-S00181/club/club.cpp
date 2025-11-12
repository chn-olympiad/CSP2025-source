#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000001][5],n;
int b[5];
int cnt[5],ans;
int T;
priority_queue<int>q[4];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		for(int i=1;i<=3;i++){
			cnt[i]=0;
			while(!q[i].empty())q[i].pop();
		}
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)cin>>a[i][j];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)b[j]=j;
			sort(b+1,b+1+3,[&](int x,int y){
				return a[i][x]>a[i][y];
			});
			cnt[b[1]]++;
			ans+=a[i][b[1]];
			q[b[1]].push(a[i][b[2]]-a[i][b[1]]);
		}
		for(int j=1;j<=3;j++){
			while(cnt[j]>n/2){
				cnt[j]--;
				ans+=q[j].top();
				q[j].pop();
			}
			
		}
		printf("%lld\n",ans);		
	}

}
