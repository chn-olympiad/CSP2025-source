#include<bits/stdc++.h>
#define int long long
#define F(i,l,r) for(int i=(l); i<=(r); ++i)
using namespace std;
const int N=1e5+50,INF=0x3f3f3f3f3f3f3f3f;

int n,ans;
int cnt[3];
int id[N],d[N];
int a[N][3];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T; cin>>T;
	F(cas,1,T){
		cin>>n;
		ans=cnt[0]=cnt[1]=cnt[2]=0;
		memset(a,0,sizeof a);
		F(i,1,n){
			id[i]=0;
			F(j,0,2){
				cin>>a[i][j];
				if(a[i][j]>a[i][id[i]]) id[i]=j;
			}
			cnt[id[i]]++;
			ans+=a[i][id[i]];
		}
		int flg=-1;
		F(i,0,2) if(cnt[i]>n/2) flg=i;
		if(flg==-1){
			cout<<ans<<'\n';
			continue;
		}
		F(i,1,n){
			int mx=0;
			F(j,0,2) if(j!=flg) mx=max(mx,a[i][j]);
			d[i]=mx-a[i][flg];
		}
		sort(d+1,d+n+1,greater<int>());
		F(i,1,n/2) if(d[i]<0) ans+=d[i];
		cout<<ans<<'\n';
	}
	
	return 0;
}
