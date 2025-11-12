#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+5;
struct node{
	int a, b, c;
	bool operator<(const node &o)const{
		if(a!=o.a)return a>o.a;
		if(b!=o.b)return b>o.b;
		return c>o.c;
	}
}m[N];
const int M = 205;
ll dp[2][M][M][M];
ll f[2][N];
void solve(){
	int n;
	cin >> n;
	bool flag=true,flag1=true;
	for(int i=1; i<=n; ++i){
		cin>>m[i].a>>m[i].b>>m[i].c;
		if(m[i].b!=0)flag=false;
		if(m[i].c!=0)flag1=false;
	}
	if(flag){
		sort(m+1,m+1+n);
		int x=0,sum=0;
		for(int i=1; i<=n; ++i){
			if(x<n/2)x++,sum+=m[i].a;
			else break;
		}
		cout << sum << '\n';
	}
	else if(flag1){
		ll ans=-1;
		bool old=0;
		for(int i=1; i<=n; ++i){
			for(int j=0; j<=n/2; ++j)
				for(int k=0; k<=n/2; ++k){
						if(j!=0)
							f[old][j]=max(f[old][j], f[1-old][j-1]+m[i].a);
						if(k!=0)
							f[old][j]=max(f[old][j], f[1-old][j]+m[i].b);
						ans=max(ans, f[old][j]);
				}
			old=1-old;
		}
		memset(f, 0, sizeof(f));
		cout << ans << '\n'; 
	}
	else{
		ll ans=-1;
		bool old=0;
		for(int i=1; i<=n; ++i){
			for(int j=0; j<=n/2; ++j)
				for(int k=0; k<=n/2; ++k){
					for(int w=0; w<=n/2; ++w){
						if(j!=0)
							dp[old][j][k][w]=max(dp[old][j][k][w], dp[1-old][j-1][k][w]+m[i].a);
						if(k!=0)
							dp[old][j][k][w]=max(dp[old][j][k][w], dp[1-old][j][k-1][w]+m[i].b);
						if(w!=0)
							dp[old][j][k][w]=max(dp[old][j][k][w], dp[1-old][j][k][w-1]+m[i].c);
						ans=max(ans, dp[old][j][k][w]);	
					}
				}
			old=1-old;
		}
		memset(dp, 0, sizeof(dp));
		cout << ans << '\n'; 
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--)solve();
	return 0;
}