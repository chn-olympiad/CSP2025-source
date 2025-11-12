#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define tu tuple<int,int,int>
#define fi first
#define se second
const int N=1e5+5;
int t,n;
int a[N][4];
int vis[N];
//priority_queue<tu,vector<tu>,greater<tu> >u;
//priority_queue<tu,vector<tu>,less<tu> >now;
int tot[4];
int ans=0;
int col[N];
int calc() {
	int res=0;
	int A=0,b=0,c=0;
	for(int i=1; i<=n; i++) {
		res+=a[i][col[i]];
		if(col[i]==1) {
			A++;
		} else if(col[i]==2) {
			b++;
		} else {
			c++;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<col[i]<<" ";
//	}
	if(A>n/2||b>n/2||c>n/2) {
		return 0;
	}
	return res;
}
void dfs(int step) {
	if(step>n) {
		ans=max(ans,calc());
		return;
	}
	for(int i=1; i<=3; i++) {
		col[step]=i;
		dfs(step+1);
	}
}
struct node {
	int val,id,type;
};
vector<node>u,now;
bool cmp1(node x, node y) {
	return x.val>y.val;
}
bool cmp2(node x, node y) {
	return x.val<y.val;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		memset(vis,0,sizeof vis);
		memset(tot,0,sizeof tot);
		u.clear(),now.clear();
		cin>>n;
		if(n<=10) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=3; j++) {
					cin>>a[i][j];
				}
			}
			dfs(1);
			//cout<<"&&&";
			cout<<ans<<"\n";
		} else {
			for(int i=1; i<=n; i++) {
				int maxn=0,pos=0;
				for(int j=1; j<=3; j++) {
					cin>>a[i][j];
					if(a[i][j]>=maxn) {
						maxn=a[i][j],pos=j;
					}
				}
				ans+=maxn;
				now.pb({maxn,i,pos});
				tot[pos]++;
				for(int j=1; j<=3; j++) {
					if(pos!=j) {
						u.pb({a[i][j],i,j});
					}
				}
			}
			sort(u.begin(),u.end(),cmp1);
			sort(now.begin(),now.end(),cmp2);
			int i=0,j=0;
			for(int x=1; x<=3; x++) {
				if(tot[x]>n/2) {
					int v=tot[x]-n/2;
					while(v) {
						while(now[i].type!=x) {
							i++;
						}
						while(u[j].type==x||u[j].id!=now[i].id) {
							j++;
						}//cout<<"yes";
						ans-=now[i].val;
						ans+=u[j].val;
						v--;
					}
				}
			}
			cout<<ans<<"\n";
		}

	}
	return 0;
}