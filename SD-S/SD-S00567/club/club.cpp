#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=201;//***
const ll INF=0x3f3f3f3f3f3f3f3f;
int a[N],b[N],c[N];
ll dp[31][31][31][31];

int t;
int n;
ll ans;
//void dfs(int num,int useA,int useB,int useC,ll w){
//	if(num==n+1){
//		ans=max(ans,w);
//	//	cout<<"ans:"<<ans<<endl;
//		return ;
//	}
//	//cout<<num<<":"<<useA<<" "<<useB<<" "<<useC<<"\n";
//	if(useA+1<=(n/2)){
//		dfs(num+1,useA+1,useB,useC,w+a[num]);
//	}
//	if(useB+1<=(n/2)){
//		dfs(num+1,useA,useB+1,useC,w+b[num]);
//	}
//	if(useC+1<=(n/2)){
//		dfs(num+1,useA,useB,useC+1,w+c[num]);
//	}
//	return ;
//}
bool cmp(int a,int b){
	return a>b;
}
ll get(int num,int Ra,int Rb,int Rc) {
	if(dp[num][Ra][Rb][Rc]!=-1) {
		return dp[num][Ra][Rb][Rc];
	}
	if(num==0) {
		if(Ra>=n/2 and Ra>=n/2 and Rc>=n/2) {
			return dp[num][Ra][Rb][Rc]=0;
		}
		return dp[num][Ra][Rb][Rc]=-INF;
	}
	ll res=0;
	if(Ra-1>=n/2) {
		res=max(res,get(num-1,Ra-1,Rb,Rc)+a[num]);
	}
	if(Rb-1>=n/2) {
		res=max(res,get(num-1,Ra,Rb-1,Rc)+b[num]);
	}
	if(Rc-1>=n/2) {
		res=max(res,get(num-1,Ra,Rb,Rc-1)+c[num]);
	}
	return dp[num][Ra][Rb][Rc]=res;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//cout<<sizeof(dp)/1024/1024<<endl;
	cin>>t;
	while(t--) {
		cin>>n;
		memset(dp,-1,sizeof dp);
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==200){
			sort(a+1,a+n+1,cmp);
			ll res=0;
			for(int i=1;i<=n/2;i++){
				res+=a[i];
			}
			cout<<res<<endl;
			
		}
		else cout<<get(n,n,n,n)<<endl;
		ans=-1;
	}
	return 0;
}

