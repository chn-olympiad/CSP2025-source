// xin ming yin xian hua , bo xue ban liu hua //
#include<bits/stdc++.h>
using namespace std;

typedef pair<ll,ll> PII;
typedef long long ll;

const ll N = 1e5+10;
ll n;
ll a[N][4];

ll slove() {
	vector<PII> l[4];
	vector<ll> lost;
	for(ll i=1; i<=n; i++) {
		//find you xian xu;
		ll xu[3] = {1,2,3};
		if(a[i][1] < a[i][2]) xu[0]=2,xu[1]=1;
		if(a[i][3] > a[i][xu[0]] ) xu[2]=xu[1],xu[1]=xu[0],xu[0]=3;
		else if(a[i][3] > a[i][xu[1]]) xu[2]=xu[1],xu[1]=3;

		bool flag = 1;
		for(ll j=0; j<3 && flag; j++) {
			ll& go=xu[j];
			//cout<<"*"<<i<<' '<<go<<'\n';
			if(l[go].size()<n/2) {
				l[go].push_back( {a[i][go],i} );

				flag = 0;
			} else {
				sort(l[go].begin(),l[go].end());
				auto m = l[go][0];
				if(a[i][go] < m.first) continue;
				else {
					lost.push_back(m.second);
					l[go][0] = { a[i][go],i };
					flag = 0;
				}
			}
		}

		for(auto i : lost) {
			ll xu[3] = {1,2,3};
			if(a[i][1] < a[i][2]) xu[0]=2,xu[1]=1;
			if(a[i][3] > a[i][xu[0]] ) xu[2]=xu[1],xu[1]=xu[0],xu[0]=3;
			else if(a[i][3] > a[i][xu[1]]) xu[2]=xu[1],xu[1]=3;

			bool flag = 1;
			for(ll j=0; j<3&&flag; j++) {
				ll& go=xu[j];
				if(l[go].size()<n/2) {
					l[go].push_back( {a[i][go],i} );
					flag = 0;
				}
			}
		}
	}

	ll ans = 0;
	for(ll i=1; i<=3; i++) {
		//cout<<i<<')';
		for(auto p:l[i]) {
			ans += p.first;
			//cout<<p.second<<' '<<p.first<<'\n';
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ll t;
	cin>>t;

	while(t--) {
		for(ll i=1; i<=n; i++) a[i][1]=0,a[i][2]=0,a[i][3]=0;

		cin>>n;
		for(ll i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}

		cout<<slove()<<'\n';

	}


	return 0;
}