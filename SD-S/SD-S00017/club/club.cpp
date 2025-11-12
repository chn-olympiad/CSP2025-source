#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,vis[N],ans,num[5];
int a[N][5];
struct node{
	int val1,val2;
	bool operator<(const node &p)const{
		return val2-val1>p.val2-p.val1;
	}
};
void calc(int op){
	priority_queue<node> q;
	for(int i=1;i<=n;i++){
		if(vis[i]==op){
			if(op==1) q.push((node){max(a[i][2],a[i][3]),a[i][1]});
			if(op==2) q.push((node){max(a[i][1],a[i][3]),a[i][2]});
			if(op==3) q.push((node){max(a[i][2],a[i][1]),a[i][3]});
		}
	}
	while(!q.empty()){
		if(num[op]<=n/2) return;
		num[op]--;
		ans-=q.top().val2;ans+=q.top().val1;
		q.pop();
	}
}
void Solve(){
	ans=0;
	cin>>n;num[1]=num[2]=num[3]=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) vis[i]=1,ans+=a[i][1];
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) vis[i]=2,ans+=a[i][2];
		else vis[i]=3,ans+=a[i][3];
	}
	for(int i=1;i<=n;i++) num[vis[i]]++;
	if(num[1]>n/2) calc(1);
	else if(num[2]>n/2) calc(2);
	else if(num[3]>n/2) calc(3);
	cout<<ans<<'\n';
}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}
