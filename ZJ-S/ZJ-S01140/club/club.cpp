#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=100010;
ll a[MAXN][3],m[MAXN],LeastReduce[MAXN],n,F[3][2]={{1,2},{0,2},{0,1}};
void solve(){
	ll ans=0,cur=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		ll temp=max(a[i][0],max(a[i][1],a[i][2]));
		ans+=temp;
		a[i][0]-=temp,a[i][1]-=temp,a[i][2]-=temp;
	}
	ll cnt[3]={};
	for(int i=0;i<n;i++){
		ll c=0;
		for(int j=1;j<=2;j++){
			if(a[i][j]==0)c=j;
		}
		cnt[c]++;
		m[i]=c;
	}
	ll c=3;
	for(int j=0;j<=2;j++){
		if(cnt[j]>n/2){
			c=j;
//			cout<<c<<' ';
		}
	}
//	cout<<"_"<<c<<'\n';
	if(c==3){
		cout<<ans<<'\n';
	}else{
		for(int i=0;i<n;i++){
			if(m[i]==c){
				LeastReduce[cur]=-max(a[i][F[c][0]],a[i][F[c][1]]);
//				cout<<i<<' '<<a[i][0]<<' '<<a[i][1]<<' '<<a[i][2]<<' '<<m[i]<<' '<<LeastReduce[i]<<'\n';
				cur++;
			}
		}
		sort(LeastReduce,LeastReduce+cur);
		for(int i=0;i<(cur-n/2);i++){
			ans-=LeastReduce[i];
//			cout<<"#"<<LeastReduce[i]<<' ';
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
