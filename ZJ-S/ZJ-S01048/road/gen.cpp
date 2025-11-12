#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
inline ll read(){ ll x; scanf("%lld",&x); return x; }

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n = 10000, m = 1000000, k = 10;

int rng(int x,int y){ return x + rnd()%(y-x+1);}
void procedure(){
	cout<<n<<" "<<m<<" "<<k<<endl;

	for(int i=1;i<=m;i++){
		int x = rng(1,n), y = rng(1,n); while(y==x) y=rng(1,n);
		cout<<x<<" "<<y<<" "<<rng(1,1e9)<<endl;
	}

	for(int i=1;i<=k;i++){
		cout<<rng(1,100)<<" ";
		for(int j=1;j<=n;j++) cout<<rng(1,1e9)<<" ";
		cout<<endl;
	}
}
int main(){
	assert(freopen("road.in","w",stdout));
	ll T=1;
	while(T--) procedure();
}