#include<bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define tmax(a,b) (a)=max((a),(b))
#define tmin(a,b) (a)=min((a),(b))
#define all(x) (x).begin(),(x).end()
#define cout(x) cout<<fixed<<setprecision(x)

using namespace std;
typedef long long LL;typedef pair<int,int> PII;
typedef vector<int> vi;typedef vector<PII> vp;
typedef array<int,3> a3;typedef vector<a3> va3;

const int N=1e5+5;
int n,cnt[5];
LL ans;
PII a[N][5];

void clear(){
	ans=0;
	for(int i=1;i<=3;i++){
		cnt[i]=0;
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j].fi;
			a[i][j].se=j;
		}
		sort(a[i]+1,a[i]+1+3,greater<PII>());
		cnt[a[i][1].se]++;
		ans+=a[i][1].fi;
	}
	int k=-1;
	for(int i=1;i<=3;i++){
		if(cnt[i]>n/2){
			k=i;
		}
	}
//	cout<<ans<<" "<<k<<"\n";
	if(~k){
		vi vec;
		for(int i=1;i<=n;i++){
			if(a[i][1].se==k){
				vec.pb(a[i][2].fi-a[i][1].fi);
//				cout<<i<<":"<<a[i][2].fi-a[i][1].fi<<"\n";
			}
		}
		sort(all(vec),greater<int>());
//		cout<<cnt[k]-(n/2)<<" "<<vec.size()<<"!\n";
		for(int i=0;i<cnt[k]-(n/2);i++){
			ans+=vec[i];
		}
	}
//	cout<<"ans:";
	cout<<ans<<"\n";
//	cout<<"\n\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--) clear(),solve();
	return 0;
}

