#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100010][3],MAX[100010],cnt[3],ans;
char c[100010];
priority_queue <int,vector<int>,greater<int> > q;
template <typename type>
inline void read(type &x) {
	x=0;bool flag(0);char ch=getchar();
	while(!isdigit(ch)) flag=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	flag?x=-x:0;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--) {
		read(n);
		memset(cnt,0,sizeof cnt);
		ans=0;
		for(int i=1;i<=n;i++) {
			read(a[i][0]),read(a[i][1]),read(a[i][2]);
			MAX[i]=max(a[i][0],max(a[i][1],a[i][2]));
		}
		for(int i=1;i<=n;i++) {
			if(a[i][0]==MAX[i]) c[i]=0,cnt[0]++;
			else if(a[i][1]==MAX[i]) c[i]=1,cnt[1]++;
			else c[i]=2,cnt[2]++;
			ans+=MAX[i];
		}
		if(cnt[0]>n/2) for(int i=1;i<=n;i++) if(!c[i]) q.push(a[i][0]-max(a[i][1],a[i][2]));
		else if(cnt[1]>n/2) for(int i=1;i<=n;i++) if(c[i]==1) q.push(a[i][1]-max(a[i][0],a[i][2]));
		else if(cnt[2]>n/2) for(int i=1;i<=n;i++) if(c[i]==2) q.push(a[i][2]-max(a[i][0],a[i][1]));
		while(q.size()>n/2) {
			ans-=q.top();
			q.pop();
		}
		cout<<ans<<"\n";
		while(!q.empty()) q.pop();
	}
	return 0;
}