#include <iostream>
#include <algorithm>
#include <vector>
#define HN (n>>1)
#define SUBMITMODE 1
#define DEBU__G_ 0
#define DEBUG DEBU__G_&&!SUBMITMODE
using namespace std;
const int kxy=100005;
int t,n;
struct psn {
	int a,b,c;
}a[kxy];
bool cmp_a(psn pa,psn pb) {
	return pa.a>pb.a;
}
bool cmp_b(psn pa,psn pb) {
	return pa.b>pb.b;
}
bool cmp_negvalue_b(psn pa,psn pb) {
	return pa.a-pa.b<pb.a-pb.b;
}
bool cmp_negvalue_a(psn pa,psn pb) {
	return pa.b-pa.a<pb.b-pb.a;
}
vector <psn> join_a,join_b;

int ans=-112425520;
void dfs(int thinkto,int nsum,int cnta,int cntb,int cntc) {
	if(thinkto==n) {
		ans=max(ans,nsum);
	}
	if(cnta>HN || cntb>HN || cntc>HN) {
		return;
	}
	if(cnta!=HN) {
		dfs(thinkto+1,nsum+a[thinkto+1].a,cnta+1,cntb,cntc);
	}
	if(cntb!=HN) {
		dfs(thinkto+1,nsum+a[thinkto+1].b,cntb,cntb+1,cntc);
	}
	if(cntc!=HN) {
		dfs(thinkto+1,nsum+a[thinkto+1].c,cntc,cntb,cntc+1);
	}
	return;
}

int main() {
	//freopen("D:\\csps\\down\\club\\club4.in","r",stdin); 
	if(SUBMITMODE) {
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		//ios::sync_with_stdio(false);
	}
	cin>>t;
	for(int it=1;it<=t;++it) {
		ans=-112425520;
		join_a.clear();
		join_b.clear();
		bool is_special_A=1,is_special_B=1;
		cin>>n;
		for(int i=1;i<=n;++i) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c!=0) {
				is_special_A=is_special_B=0;
			} else if(a[i].b!=0) {
				is_special_A=0;
			}
		}
		if(is_special_A) {
			sort(a+1,a+1+n,cmp_a);
			int ans=0;
			for(int i=1;i<=(n>>1);++i) {
				ans+=a[i].a;
			}
			cout<<ans<<'\n';
		} else if(is_special_B && false) {
			
			// special B Disabled
			
			/*int ans=0;
			for(int i=1;i<=n;++i) {
				if(a[i].a>a[i].b) {
					join_a.push_back(a[i]);
					ans+=a[i].a;
				} else if(a[i].a==a[i].b) {
					if(join_a.size()<join_b.size()) {
						join_a.push_back(a[i]);
						ans+=a[i].a;
					} else {
						join_b.push_back(a[i]);
						ans+=a[i].b;
					}
				} else {
					join_b.push_back(a[i]);
					ans+=a[i].b;
				}
			}
			if(join_a.size()>(n>>1)) {
				sort(join_a.begin(),join_a.end(),cmp_negvalue_b);
				int need_rempd=join_a.size()-(n>>1);
				for(int i=0;i<need_rempd;++i) {
					ans-=(a[i].a-a[i].b);
				}
			} else if(join_b.size()>(n>>1)) {
				sort(join_b.begin(),join_b.end(),cmp_negvalue_a);
				int need_rempd=join_b.size()-(n>>1);
				for(int i=0;i<need_rempd;++i) {
					ans-=(a[i].b-a[i].a);
				}
			}
			cout<<ans<<'\n';*/
		} else {
			// special C -baked
			/*
			int ans=0;
			for(int i=1;i<=n;++i) {
				if(a[i].a>=a[i].b && a[i].a>=a[i].c) {
					ans+=a[i].a;
				} else if(a[i].b>=a[i].c){
					ans+=a[i].b;
				} else {
					ans+=a[i].c;
				}
			}
			cout<<ans<<'\n';*/
			
			
			// other
			dfs(0,0,0,0,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
