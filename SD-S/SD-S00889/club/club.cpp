#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=3e5;
int a[N][5];
int n;
vector<int>g[5];
void solve() {
	g[1].clear();
	g[2].clear();
	g[3].clear();
	n=read();
	int ans=0;
	for(int i=1; i<=n; i++) {
		a[i][1]=read();
		a[i][2]=read();
		a[i][3]=read();
		int maxn=max(a[i][1],max(a[i][2],a[i][3]));
		ans+=maxn;
		if(a[i][3]==maxn) {
			g[3].push_back(a[i][3]-max(a[i][1],a[i][2]));
		}
		else if(a[i][2]==maxn) {
			g[2].push_back(a[i][2]-max(a[i][1],a[i][3]));
		}
		else if(a[i][1]==maxn) {
			g[1].push_back(a[i][1]-max(a[i][2],a[i][3]));
		}
	}
	int len1=g[1].size();
	int len2=g[2].size();
	int len3=g[3].size();
	if(max(len1,max(len2,len3))<=n/2) {
		cout<<ans<<"\n";
		return;
	}
	if(len1>n/2) {
		int sum=len1-n/2;
		sort(g[1].begin(),g[1].end());
		for(int i=0; i<len1; i++) {
			sum--;
			ans-=g[1][i];
			if(sum==0) {
				cout<<ans<<"\n";
				return;
			}
		}
		return;
	}
	if(len2>n/2) {
		int sum=len2-n/2;
		sort(g[2].begin(),g[2].end());
		for(int i=0; i<len2; i++) {
			sum--;
			ans-=g[2][i];
			if(sum==0) {
				cout<<ans<<"\n";
				return;
			}
		}
		return;
	}
	if(len3>n/2) {
		int sum=len3-n/2;
		sort(g[3].begin(),g[3].end());
		for(int i=0; i<len3; i++) {
			sum--;
			ans-=g[3][i];
			if(sum==0) {
				cout<<ans<<"\n";
				return;
			}
		}
		return;
	}
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)solve();
	return 0;
}
