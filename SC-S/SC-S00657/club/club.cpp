#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair

const int N=1e5+3;

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

using namespace std;

int n,res;
int cnt[4];
struct node{pii x[4];}a[N];

bool cmp(node A,node B){
	return A.x[3].fi-A.x[2].fi>B.x[3].fi-B.x[2].fi;
}

void solve(){
	n=read();res=0;
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j) a[i].x[j].fi=read(),a[i].x[j].se=j;
		sort(a[i].x+1,a[i].x+4);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		if(cnt[a[i].x[3].se]>=n/2) res+=a[i].x[2].fi,cnt[a[i].x[2].se]++;
		else res+=a[i].x[3].fi,cnt[a[i].x[3].se]++;
	}
	cout<<res<<'\n';
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}