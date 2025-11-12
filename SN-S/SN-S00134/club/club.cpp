#include<bits/stdc++.h>
using namespace std;
int t,n,dp[134343];
struct Node{
	int a,b,c;
}a[102323];
inline bool cmp(Node q,Node g){
	int g1=q.a+q.b+q.c,g2=g.a+g.c+g.b;
	return g1<=g2;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c,dp[i]=0;
	int g=n/2;
	int fq=g,fw=g,fe=g;
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		int as=max(max(a[i].a,a[i].b),a[i].c),mn=min(min(a[i].a,a[i].b),a[i].c),md=a[i].a+a[i].b+a[i].c-mn-as;
		if(as==a[i].a&&fq){
			fq--,ans+=as;
		}else if(as==a[i].b&&fw){
			fw--,ans+=as;
		}else if(as==a[i].c&&fe){
			fe--,ans+=as;
		}else if(md==a[i].a&&fq){
			fq--,ans+=md;
		}else if(md==a[i].b&&fw){
			fw--,ans+=md;
		}else if(md==a[i].c&&fe){
			fe--,ans+=md;
		}else if(mn==a[i].a&&fq){
			fq--,ans+=mn;
		}else if(mn==a[i].b&&fw){
			fw--,ans+=mn;
		}else if(mn==a[i].c&&fe){
			fe--,ans+=mn;
		}else break;
	}
	cout<<ans<<'\n';
}
int main(){
//	ifstream in("club.in");
//	ofstream out("club.out");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--) solve();
	return 0;
} 
