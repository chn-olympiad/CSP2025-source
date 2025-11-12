#include<bits/stdc++.h>
#define maxn 2010001
#define int long long
using namespace std;
const int Mod=998244353,inf=1e9+7,V=2e4+1;
mt19937 yrand(time(0));
typedef long long ll;
int reduce(int x){return x-(x>=Mod)*Mod;}

int n=1e5;
void solve(){
	cout<<n<<'\n';
	for(int i=1;i<=n;i++){
		vector<int>vec;
		vec.push_back(yrand()%V);
		vec.push_back(yrand()%V);
		vec.push_back(yrand()%V);
//		nth_element(vec.begin(),vec.end(),vec.begin()+2);
//		swap(vec[1],vec[2]);
		for(int i:vec) cout<<i<<' ';cout<<'\n';
	}
}
signed main(){
	#ifdef LOCAL
	freopen("test.in","w",stdout);
	#endif
	ios::sync_with_stdio(0);cin.tie(0);
//	init();
	int T=5;
	cout<<T<<'\n';
	while(T--) solve();
	#ifdef LOCAL
	cerr<<"Time: "<<clock()<<" ms\n";
	#endif
	return 0;
}
