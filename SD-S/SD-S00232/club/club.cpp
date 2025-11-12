#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N = 5e5+1145;
int n,t,tot,v[N][3],bk[N];
ll ans;
vector<int> tong[3];
struct ar {
	int v,id,b;
} a[N];
bool cmp(ar l,ar r) {
	return l.v>r.v;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		tot=3,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) bk[i]=0;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[tot-2].v,&a[tot-1].v,&a[tot].v);
			a[tot].id=a[tot-1].id=a[tot-2].id=i;
			a[tot].b=2,a[tot-1].b=1,a[tot-2].b=0;
			v[i][0]=a[tot-2].v,v[i][1]=a[tot-1].v,v[i][2]=a[tot].v;
			tot+=3;
		}
		tot-=3;
		sort(a+1,a+1+tot,cmp);
		for(int i=1,j=1; j<=n; j++) {
			while(bk[a[i].id]) i++;
			ans+=a[i].v;
			tong[a[i].b].push_back(a[i].id);
			bk[a[i].id]=1;
		}
		int t=-1;
		if(tong[1].size()>n/2) t=1;
		if(tong[0].size()>n/2) t=0;
		if(tong[2].size()>n/2) t=2;
		if(t==-1) printf("%lld\n",ans);
		else {
			int ti=(t+1)%3,tj=(t+2)%3;
			vector<int> qwq;
			for(auto i:tong[t]) qwq.push_back(min(v[i][t]-v[i][ti],v[i][t]-v[i][tj]));
			sort(qwq.begin(),qwq.end());
			for(int i=0; i<tong[t].size()-n/2; i++) ans-=qwq[i];
			printf("%lld\n",ans);
		}
		tong[0].clear(),tong[1].clear(),tong[2].clear();
	}
	return 0;
}
