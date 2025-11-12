#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
int n,ans;
int vis[N],cnt[5];
struct diff {
	int id,difff,group;
	friend bool operator < (diff x,diff y) {
		return x.difff<y.difff;
	}
} dif[N];
struct person {
	int id,d1,d2,d3;
} a[N];
void dfs1(int k,int aa,int bb,int cc) {
	if(aa>n/2) {
		return;
	}
	if(bb>n/2) {
		return;
	}
	if(cc>n/2) {
		return;
	}
	if(k>n) {
		int sum=0;
		for(int i=1; i<=n; i++) {
			if(vis[i]==1) {
				sum+=a[i].d1;
			} else if(vis[i]==2) {
				sum+=a[i].d2;
			} else {
				sum+=a[i].d3;
			}
		}
		ans=max(ans,sum);
		return;
	}
	vis[k]=1;
	dfs1(k+1,aa+1,bb,cc);
	vis[k]=2;
	dfs1(k+1,aa,bb+1,cc);
	vis[k]=3;
	dfs1(k+1,aa,bb,cc+1);
}
bool cmp1(person x,person y) {
	return x.d1<y.d1;
}
bool cmp2(person x,person y) {
	return x.d2<y.d2;
}
bool cmp3(person x,person y) {
	return x.d3<y.d3;
}
bool cmp4(person x,person y) {
	return x.id<y.id;
}
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		int flag1,flag2,flag3;
		cnt[1]=cnt[2]=ans=flag1=flag2=flag3=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			a[i].id=i;
			if(a[i].d1==0) {
				flag1++;
			} else if(a[i].d2==0) {
				flag2++;
			} else if(a[i].d3==0) {
				flag3++;
			}
		}
		if(n<=10) {
			memset(vis,0,sizeof(vis));
			dfs1(1,0,0,0);
			cout<<ans<<"\n";
		} else if(flag3==n&&flag2==n) {
			sort(a+1,a+1+n,cmp1);
			for(int i=n; i>n/2; i++) {
				ans+=a[i].d1;
			}
			cout<<ans<<"\n";
		} else if(flag3==n) {
			for(int i=1; i<=n; i++) {
				dif[i].difff=abs(a[i].d1-a[i].d2);
				if(a[i].d1<a[i].d2) {
					dif[i].id=2;
					dif[i].group=a[i].id;
				} else {
					dif[i].id=1;
					dif[i].group=a[i].id;
				}
			}
			sort(dif+1,dif+1+n);
			for(int i=n; i>=1; i--) {
				cnt[dif[i].id]++;
				if(cnt[dif[i].id]<=n/2) {
					if(dif[i].id==1) {
						ans+=a[dif[i].group].d1;
					} else {
						ans+=a[dif[i].group].d2;
					}
				} else {
					if(dif[i].id==1) {
						ans+=a[dif[i].group].d2;
					} else {
						ans+=a[dif[i].group].d1;
					}
				}
			}
			cout<<ans<<"\n";
		} else {
			for(int i=1; i<=n; i++) {
				ans+=max(a[i].d1,max(a[i].d2,a[i].d3));
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}