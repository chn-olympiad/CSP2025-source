#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans;
struct node {
	int a,b,c;
	int aa,bb,cc;
	int id,p;
} p[100005],p1[100005],p2[100005];
bool cmp1(node a,node b) {
	return a.aa>b.aa;
}
bool cmp2(node a,node b) {
	return a.bb>b.bb;
}
bool cmp3(node a,node b) {
	return a.cc>b.cc;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) {
		bool vis[100005]={};
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>p[i].a>>p[i].b>>p[i].c;
			p1[i].a=p2[i].a=p[i].a;
			p1[i].b=p2[i].b=p[i].b;
			p1[i].c=p2[i].c=p[i].c;
			p[i].id=p1[i].id=p2[i].id=i;
			p[i].aa=p[i].a-p[i].b-p[i].c;
			p1[i].bb=p[i].b-p[i].a-p[i].c;
			p2[i].cc=p[i].c-p[i].a-p[i].b;
			if(p[i].aa>p2[i].cc&&p[i].aa>p1[i].bb) p1[i].p=p2[i].p=p[i].p=1;
			if(p1[i].bb>p2[i].cc&&p1[i].bb>p[i].aa) p1[i].p=p2[i].p=p[i].p=2;
			if(p2[i].cc>p[i].aa&&p2[i].cc>p1[i].bb) p1[i].p=p2[i].p=p[i].p=3;
		}
//		for(int i=1;i<=n;i++){
//			cout<<p[i].aa<<" "<<p1[i].bb<<" "<<p2[i].cc<<" "<<p[i].p<<"\n";
//		}
		sort(p+1,p+n+1,cmp1);
		sort(p1+1,p1+n+1,cmp2);
		sort(p2+1,p2+n+1,cmp3);
		int k1=0,k2=0,k3=0;
		for(int i=1; i<=n; i++) {
			if(p[i].p==1&&k1<n/2) {
				vis[p[i].id]=1;
				ans+=p[i].a;
				k1++;
				//cout<<p[i].a<<" "<<ans<<" 1\n";
			}
		}
		for(int i=1; i<=n; i++) {
			if(p1[i].p==2&&k2<n/2) {
				vis[p1[i].id]=1;
				ans+=p1[i].b;
				k2++;
				//cout<<p1[i].b<<" "<<ans<<" 2\n";
			}
		}
		for(int i=1; i<=n; i++) {
			if(p2[i].p==3&&k3<n/2) {
				vis[p2[i].id]=1;
				ans+=p2[i].c;
				k3++;
				//cout<<p2[i].c<<" "<<ans<<" 3\n";
			}
		}
		if(k1+k2+k3<n) {
			for(int i=1; i<=n; i++) {
				if(!vis[p[i].id]) {
					ans+=max({(k1<n/2)?p[i].a:0,(k2<n/2)?p[i].b:0,(k3<n/2)?p[i].c:0});
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<vis[i]<<" "<<p[i].a<<" ";
//		}
		cout<<ans<<"\n";
	}
	return 0;
}

