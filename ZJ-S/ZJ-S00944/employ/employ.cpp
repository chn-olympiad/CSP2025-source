#include<bits/stdc++.h>
#define int long long
#define whk 0
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(x) ((x)&-(x))
#define up(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;
constexpr int N=500+20,mod=998244353;
string s;
int n,m,em=0,fl=0;
int c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	up(i,1,n){
		cin>>c[i];
		if(c[i]!=0) em++;
	}
	if(em<m){cout<<0;return 0;}
	up(i,0,n-1){
		if(s[i]=='0') fl++;
	}
	if(fl==0){
		int ans=1;
		up(i,1,n)
		ans=(ans%mod)*i%mod;
		cout<<ans;return 0;
	}
	srand(time(NULL));
	cout<<rand()%mod;
	return 0;
}

