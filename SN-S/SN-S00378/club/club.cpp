#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],b[100005],c[100005];
void solve(void){
	int n,ans=0;
	cin>>n;
	priority_queue<int,vector<int>,greater<int> > q1,q2,q3;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=n;i++){
		if(a[i]>b[i]&&a[i]>c[i]){
			if(q1.size()<n/2) q1.push(a[i]-max(b[i],c[i])),ans+=a[i];
			else if(q1.top()<(a[i]-max(b[i],c[i]))) ans-=q1.top(),q1.pop(),q1.push(a[i]-max(b[i],c[i])),ans+=a[i];
		}
		if(b[i]>a[i]&&b[i]>c[i]){
			if(q2.size()<n/2) q2.push(b[i]-max(a[i],c[i])),ans+=b[i];
			else if(q2.top()<(b[i]-max(a[i],c[i]))) ans-=q2.top(),q2.pop(),q2.push(b[i]-max(a[i],c[i])),ans+=b[i];
		}
		if(c[i]>b[i]&&c[i]>a[i]){
			if(q3.size()<n/2) q3.push(c[i]-max(a[i],b[i])),ans+=c[i];
			else if(q3.top()<(c[i]-max(a[i],b[i]))) ans-=q3.top(),q3.pop(),q3.push(c[i]-max(a[i],b[i])),ans+=c[i];
		}
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
