#include <bits/stdc++.h>
#define pii pair<int,int>
const int N=1e5+5;
using namespace std;
int a[N][3];
int cnt[3];
void solve(){
	cnt[0]=cnt[1]=cnt[2]=0;
	priority_queue<int> q; 
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		pii com[3]={{a[i][0],0},{a[i][1],1},{a[i][2],2}};
		sort(com,com+3);
		cnt[com[2].second]++;
	}
	int maxx;
	if(cnt[0]>cnt[1]){
		if(cnt[0]>cnt[2]) maxx=0;
		else maxx=2 ;
	}
	else{
		if(cnt[1]>cnt[2]) maxx=1;
		else maxx=2;
	}
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++){
		pii com[3]={{a[i][0],0},{a[i][1],1},{a[i][2],2}};
		sort(com,com+3);
		ans+=com[2].first;
		if(com[2].second==maxx) q.push(com[1].first-com[2].first);
		cnt[com[2].second]++;
		if(cnt[com[2].second]>n/2){
			ans+=q.top();
			q.pop();
			cnt[com[2].second]--;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
