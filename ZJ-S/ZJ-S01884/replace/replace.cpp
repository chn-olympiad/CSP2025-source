#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1[200005],t2[200005];
namespace bl {
	int h[2005],h2[2005],hs[1005],hs2[1005],pw[2005];
	const int M1=998244853, M2=1000000007, B1=131, B2=13331;
	void inith() {
		for(int i=1; i<=n; i++) {
			int x=0;
			for(int j=0; j<s1[i].size(); j++) x=((i==0?0:1ll*x*B1)+s1[i][j])%M1;
			hs[i]=x;
			x=0;
			for(int j=0; j<s2[i].size(); j++) x=((i==0?0:1ll*x*B1)+s2[i][j])%M1;
			hs2[i]=x;
		}
	}
	void inith2(int T) {
		for(int i=0; i<t1[T].size(); i++) {
			h[i]=((i==0?0:1ll*h[i-1]*B1)+t1[T][i])%M1;
			h2[i]=((i==0?0:1ll*h2[i-1]*B1)+t2[T][i])%M1;
		}
	}
	int geth(int l, int r, int *x) {
		return ((x[r]-1ll*pw[r-l+1]*x[l-1])%M1+M1)%M1;
	}
	void main() {
		pw[0]=1;
		for(int i=1; i<=2000; i++) pw[i]=1ll*pw[i-1]*B1%M1;
		inith();
		for(int T=1; T<=q; T++) {
			if(t1[T].size()!=t2[T].size()) {
				cout<<0<<'\n';
				continue;
			}
			inith2(T);
			int p=t1[T].size()-1,q=-1;
			for(int i=0; i<t1[T].size(); i++) {
				if(t1[T][i]!=t2[T][i]) {
					p=i;
					break;
				}
			}
			for(int i=t1[T].size(); i>=0; i--) {
				if(t1[T][i]!=t2[T][i]) {
					q=i;
					break;
				}
			}
			int ans=0;
//		printf("p=%d q=%d\n",p,q);
			for(int i=0; i<=p; i++) {
				for(int j=1; j<=n; j++) {
					int ed=i+s1[j].size()-1;
					if(ed>=q && ed<t1[T].size() && geth(i,ed,h)==hs[j] && geth(i,ed,h2)==hs2[j]) {
//					printf("j=%d [%d,%d]",j,i,ed);
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
}
namespace B {
	typedef pair<int,int> pii;
	__gnu_pbds::tree<pii,__gnu_pbds::null_type,less<pii>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>
	tr[4000005];
	struct node {
		int l,r,d,id;
	} a[200005],b[200005];
	bool cmp(node x, node y) {
		return x.r < y.r;
	}
	int tot,ans[200005];
	void main() {
		for(int T=1; T<=n; T++) {
			int p1,p2;
			for(int i=0; i<s1[T].size(); i++)
				if(s1[T][i]=='b') p1=i;
			for(int i=0; i<s2[T].size(); i++)
				if(s2[T][i]=='b') p2=i;
			if(p1<=p2) b[T]= {p1,s1[T].size()-p2-1,p2-p1};
			else b[T]= {p2,s1[T].size()-p1-1,p2-p1};
		}
//		for(int i=1; i<=n; i++) {
//			printf("(%d,%d,%d)\n",b[i].l,b[i].r,b[i].d);
//		}
		for(int T=1; T<=q; T++) {
			if(t1[T].size()!=t2[T].size()) {
				ans[T]=0;
				continue;
			}
			int p1,p2;
			for(int i=0; i<t1[T].size(); i++)
				if(t1[T][i]=='b') p1=i;
			for(int i=0; i<t2[T].size(); i++)
				if(t2[T][i]=='b') p2=i;
			if(p1<=p2) a[++tot]= {p1,t1[T].size()-p2-1,p2-p1,T};
			else a[++tot]= {p2,t1[T].size()-p1-1,p2-p1,T};
		}
		sort(a+1,a+1+tot,cmp);
		sort(b+1,b+1+n,cmp);
		for(int i=1,j=1; i<=tot; i++) {
//			printf("1");
			while(j<=n && b[j].r<=a[i].r) {
				tr[b[j].d+2000000].insert({b[j].l, j});
				j++;
			}
//			printf("2 %d\n",a[i].d);
			ans[a[i].id]=tr[a[i].d+2000000].order_of_key({a[i].l, 1e9});
		}
		for(int i=1; i<=q; i++) cout<<ans[i]<<'\n';
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int L1=0, L2=0;
	for(int i=1; i<=n; i++) cin>>s1[i]>>s2[i], L1+=s1[i].size()+s2[i].size();
	for(int i=1; i<=q; i++) cin>>t1[i]>>t2[i], L2+=t1[i].size()+t2[i].size();
	if(n<=1000 && q<=1000 && L1<=2000 && L2<=2000) bl::main();
	else B::main();
	return 0;
}
