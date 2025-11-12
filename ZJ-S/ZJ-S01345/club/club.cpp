#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int mx=2e5+5;
ll t,n,ret,a[mx][3],tj1[mx],tj2[mx],vis[mx],b[mx],tot;
void colse(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve(){
	cin>>n;
	vis[0]=vis[1]=vis[2]=0;tot=0;
	ll ret=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++) cin>>a[i][j];
		int _1=max({a[i][0],a[i][1],a[i][2]}),_2=min({a[i][0],a[i][1],a[i][2]});
		ret+=_1;tj2[i]=_1-(a[i][0]+a[i][1]+a[i][2]-_1-_2);
		if(a[i][0]==_1) vis[0]++,tj1[i]=0;
		else if(a[i][1]==_1) vis[1]++,tj1[i]=1;
		else vis[2]++,tj1[i]=2;
	}
	int bj=-1;
	for(int i=0;i<3;i++) if(vis[i]>n/2) bj=i;
	if(bj!=-1){
		for(int i=1;i<=n;i++){
			if(tj1[i]==bj){
				b[++tot]=tj2[i];
			}
		}
		sort(b+1,b+tot+1);
		for(int i=1;i<=vis[bj]-n/2;i++) ret-=b[i];
	}
	cout<<ret<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	colse();
	cin>>t;
	while(t--) solve();
	return 0;
}