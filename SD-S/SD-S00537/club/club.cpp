#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
int tp[100005],gr[4][100005],cnt[4];
pair<int,int> dj[100005];
int a[100005];
int ans,zu[100005],G1,G2,G3;
bool bo=true;
struct node {
	int a,b,c;
} p[100005];
void dfs(int dep) {
	if(G1>(n>>1))return;
	if(G2>(n>>1))return;
	if(G3>(n>>1))return;
	if(dep==n+1) {
		int daan=0;
		for(int i=1; i<=n; i++) {
			if(zu[i]==1)daan+=p[i].a;
			if(zu[i]==2)daan+=p[i].b;
			if(zu[i]==3)daan+=p[i].c;
		}
		ans=max(ans,daan);
		return;
	} else {
		zu[dep]=1;
		G1++;
		dfs(dep+1);
		zu[dep]=2;
		G1--;
		G2++;
		dfs(dep+1);
		zu[dep]=3;
		G2--;
		G3++;
		dfs(dep+1);
		G3--;
	}
}
void solve() {
	bo=true;
	cin>>n;
	ans=0;
	memset(a,0,sizeof(a));
	memset(gr,0,sizeof(gr));
	memset(cnt,0,sizeof(cnt));
	memset(dj,0,sizeof(dj));
	for(int i=1; i<=n; i++) {
		cin>>p[i].a>>p[i].b>>p[i].c;
		if(p[i].b!=0||p[i].c!=0)bo=false;
	}
	if(bo) {
		for(int i=1; i<=n; i++)a[i]=p[i].a;
		sort(a+1,a+1+n);
		int ans=0;
		for(int i=(n>>1)+1; i<=n; i++)ans+=a[i];
		cout<<ans<<'\n';
	} else if(n<=10) {
		dfs(1);
		cout<<ans<<'\n';
	} else {
		for(int i=1; i<=n; i++) {
			if(p[i].a>p[i].b&&p[i].a>p[i].c)tp[i]=1;
			else if(p[i].b>p[i].a&&p[i].b>p[i].c)tp[i]=2;
			else if(p[i].c>p[i].b&&p[i].c>p[i].a)tp[i]=3;
		}
		for(int i=1; i<=n; i++) {
			if(tp[i]==1)gr[1][++cnt[1]]=i;
			if(tp[i]==2)gr[2][++cnt[2]]=i;
			if(tp[i]==3)gr[3][++cnt[3]]=i;
		}
		if(cnt[1]<=(n>>1)&&cnt[2]<=(n>>1)&&cnt[3]<=(n>>1)) {
			int ans=0;
			for(int i=1; i<=cnt[1]; i++)ans+=p[gr[1][i]].a;
			for(int i=1; i<=cnt[2]; i++)ans+=p[gr[2][i]].b;
			for(int i=1; i<=cnt[3]; i++)ans+=p[gr[3][i]].c;
			cout<<ans<<'\n';
		} else {
			int ans=0;

			if(cnt[1]<=(n>>1)&&cnt[2]<=(n>>1)&&cnt[3]<=(n>>1)) {
				int ans=0;
				for(int i=1; i<=cnt[1]; i++)ans+=p[gr[1][i]].a;
				for(int i=1; i<=cnt[2]; i++)ans+=p[gr[2][i]].b;
				for(int i=1; i<=cnt[3]; i++)ans+=p[gr[3][i]].c;
				cout<<ans<<'\n';
			} else {
				int anss=0;
				if(cnt[1]>(n>>1)) {
					for(int i=1; i<=cnt[1]; i++)dj[i].first=max(p[gr[1][i]].b,p[gr[1][i]].c)-p[gr[1][i]].a;
					for(int i=1; i<=cnt[1]; i++)dj[i].second=i;
					sort(dj+1,dj+1+cnt[1]);
					for(int i=1; i<=cnt[1]-(n>>1); i++)anss+=dj[i].first;
					for(int i=cnt[1]-(n>>1)+1; i<=n; i++)anss+=p[gr[1][dj[i].second]].a;
				}
				if(cnt[2]>(n>>1)) {
					for(int i=1; i<=cnt[2]; i++)dj[i].first=max(p[gr[2][i]].a,p[gr[2][i]].c)-p[gr[2][i]].b;
					for(int i=1; i<=cnt[2]; i++)dj[i].second=i;
					sort(dj+1,dj+1+cnt[2]);
					for(int i=1; i<=cnt[2]-(n>>1); i++)anss+=dj[i].first;
					for(int i=cnt[2]-(n>>1)+1; i<=n; i++)anss+=p[gr[2][dj[i].second]].b;
				}
				if(cnt[3]>(n>>1)) {
					for(int i=1; i<=cnt[3]; i++)dj[i].first=max(p[gr[3][i]].a,p[gr[3][i]].b)-p[gr[3][i]].c;
					for(int i=1; i<=cnt[3]; i++)dj[i].second=i;
					sort(dj+1,dj+1+cnt[3]);
					for(int i=1; i<=cnt[3]-(n>>1); i++)anss+=dj[i].first;
					for(int i=cnt[3]-(n>>1)+1; i<=n; i++)anss+=p[gr[3][dj[i].second]].c;
				}
				cout<<anss;
			}
		}
	}
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)solve();
	return 0;
}
