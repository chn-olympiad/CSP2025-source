#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n;
struct node{
	ll x,id;
}a[100005][4],zy[100005];
bool f[100005];
bool cmp(node p,node q){
	return p.x>q.x; 
}
void solve(){
	cin>>n;
	ll ans=0,x[4]={0};
	memset(zy,0,sizeof(zy)),memset(a,0,sizeof(a)),memset(f,0,sizeof(f));
	for(ll i=1;i<=n;i++){
		cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
		a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
		sort(a[i]+1,a[i]+4,cmp);
		ans+=a[i][1].x;
		x[a[i][1].id]++;
		zy[i].x=a[i][2].x-a[i][1].x,zy[i].id=i;
	}
	ll nd=(x[1]>n/2?1:((x[2]>n/2)?2:(x[3]>n/2)?3:-1));
	for(ll i=1;i<=n;i++){
		if(a[i][1].id==nd)f[i]=1;
	}
	sort(zy+1,zy+n,cmp);
	for(ll j=1;nd!=-1&&x[nd]>n/2;j++){
		if(!f[zy[j].id])continue;
		ans+=zy[j].x,x[nd]--;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),cout.tie(0)->sync_with_stdio(0);
	cin>>T;
	while(T--){
		solve();
	}
}
/*
思量怎向，迟回独掩青扉，斜阳犹照南陌。 
*/
