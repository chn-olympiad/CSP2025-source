#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define cmax(a,b) ((a)=max((a),(b)))
#define cmin(a,b) ((a)=min((a),(b)))
#define pb emplace_back
#define int long long
using namespace std;
const int N=1e5+10;
int T,n,cnt[3];pii a[N][3];
struct node{
	int s,t,d;
	bool operator <(const node t)const{
		return d<t.d;
	}
}b[N];
void Mysolve(){
	cnt[0]=cnt[1]=cnt[2]=0;
	cin>>n;int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<3;++j)cin>>a[i][j].fi,a[i][j].se=j;
		sort(a[i],a[i]+3);ans+=a[i][2].fi;cnt[a[i][2].se]++;
		b[i]={a[i][2].se,a[i][1].se,a[i][2].fi-a[i][1].fi};
	}
	sort(b+1,b+1+n);
	pii mx={0,0};for(int j=0;j<3;++j)cmax(mx,make_pair(cnt[j],j));
	int cur=0;
	for(int i=1;cur<(mx.fi-n/2);++i){
		if(b[i].s==mx.se)ans-=b[i].d,++cur;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>T;while(T--)Mysolve();
	return 0;
}