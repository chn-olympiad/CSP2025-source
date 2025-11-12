#include<bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pb push_back
const int N=2e6;
using namespace std;
int a[N][5],anss=0,cnt[5],vis[N],ans=0,m=0;
struct node{
	int to,dis,p;
};
bool cmp(node a,node b){
	return a.dis<b.dis;
}
node pque[N];
void solve(){
	int n;
	cin>>n;
	anss=0,ans=0,m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		anss+=a[i][1];
		pque[++m]={2,a[i][2]-a[i][1],i};
		pque[++m]={3,a[i][3]-a[i][1],i};
	}
	sort(pque+1,pque+m+1,cmp);
	cnt[1]=n;
	while(m>0 and (cnt[1]>n/2 or pque[m].dis>0)){
		node t=pque[m];
		m--;
		if(!vis[t.p] and cnt[t.to]<n/2){
			anss+=t.dis;
			cnt[t.to]++;
			cnt[1]--;
			vis[t.p]=1;
		}
	} 
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	cnt[1]=0,cnt[2]=0,cnt[3]=0; 
	ans=max(ans,anss);
	
	anss=0,m=0;
	for(int i=1;i<=n;i++){
		anss+=a[i][2]; 
		pque[++m]={1,a[i][1]-a[i][2],i};
		pque[++m]={3,a[i][3]-a[i][2],i};
	}
	sort(pque+1,pque+m+1,cmp);
	cnt[2]=n;
	while(m>0 and (cnt[2]>n/2 or pque[m].dis>0)){
		node t=pque[m];
		m--;
		if(!vis[t.p] and cnt[t.to]<n/2){
			anss+=t.dis;
			cnt[t.to]++;
			cnt[2]--;
			vis[t.p]=1;
		}
	} 
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	cnt[1]=0,cnt[2]=0,cnt[3]=0; 
	ans=max(ans,anss);
	
	
	anss=0,m=0;
	for(int i=1;i<=n;i++){
		anss+=a[i][3];
		pque[++m]={1,a[i][1]-a[i][3],i};
		pque[++m]={2,a[i][2]-a[i][3],i};
	}
	sort(pque+1,pque+m+1,cmp);
	cnt[3]=n;
	while(m>0 and (cnt[3]>n/2 or pque[m].dis>0)){
		node t=pque[m];
		m--;
		if(!vis[t.p] and cnt[t.to]<n/2){
			anss+=t.dis;
			cnt[t.to]++;
			cnt[3]--;
			vis[t.p]=1;
		}
	} 
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	cnt[1]=0,cnt[2]=0,cnt[3]=0; 
	ans=max(ans,anss);
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
