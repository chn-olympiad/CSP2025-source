#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=114514;

struct qwq {
	int id,val;
} a[4];

bool cmp(qwq x,qwq y) {
	return x.val<y.val;
}

int T;
int n;
int cnt[4];

vector <int >v[6][4];

void init() {
	memset(cnt,0,sizeof(cnt));
}

void solve() {
	cin>>n;
	int ans=0;
	init();
	for(int i=1; i<=n; i++) {
		cin>>a[1].val>>a[2].val>>a[3].val;
		a[1].id=1,a[2].id=2,a[3].id=3;

		if(a[1].val<a[2].val) swap(a[1],a[2]);
		if(a[2].val<a[3].val) swap(a[2],a[3]);
		if(a[1].val<a[2].val) swap(a[1],a[2]);

		cnt[a[1].id]++;
		ans+=a[1].val;
		v[T][a[1].id].push_back(a[1].val-a[2].val);
	}

	int mxid=1;

	if(cnt[2]>cnt[1]) {
		mxid=2;
		if(cnt[3]>cnt[2]) mxid=3;
	}
	if(cnt[3]>cnt[1]) mxid=3;

	if(cnt[mxid]>n/2) {
		sort(v[T][mxid].begin(),v[T][mxid].end());
		for(int i=0; i<cnt[mxid]-n/2; i++) {
			ans-=v[T][mxid][i];
		}
	}

	cout<<ans;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

//  freopen("club.in","r",stdin);
//  freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>T;
	while(T--) {
		solve();
		cout<<endl;
	}
}

// wo yao shang mi huo xing wei da shang

//ZJ-J01310
//ZJ-J01344

//15:49 AC

//%%% Clv_Csy
//%%% Brute_Force
//%%% yyc
//%%% fede
//%%% __Segment__
//%%% myself(doge)

//luogu uid = 1300065 ? (binary_carrots)

/*
  rrr   rrr      p ppppppppppp			  ++					  ++
   rr rr          ppp        pp      	  ++					  ++
   rrr   		  pp 		 pp           ++					  ++
   rr			  pp		pp  ++++++++++++++++++++++	+++++++++++++++++++++
   rr			  ppppppppppp	++++++++++++++++++++++	+++++++++++++++++++++
   rr			  pp					  ++					  ++
   rr			  pp					  ++					  ++
   rr			  pp					  ++					  ++
   rr			  pp					  ++					  ++
   rr			  pp					  ++					  ++
*/
