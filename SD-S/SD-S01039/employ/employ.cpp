#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=1;i>=b;i--)
#define ll long long
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int N=1e6+5;
const int P=1e9+7;
int a[N],p[N];
void solve()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>p[i];
	}
	if(n<=18){
		for(int i=0;i<n;++i){
			a[i+1]=i+1;
		}
		int ans=0;
		do{
			int now=0;
			int cnt=0;
			for(int i=1;i<=n;++i){
				if(cnt>=p[a[i]]){
					cnt++;
					continue;
				}
				if(s[i-1]=='1'){
					now++;
					continue;
				}
				else{
					cnt++;
				}
			}
			if(now>=m){
				ans=(ans+1)%998244353;
			}
		}while(next_permutation(a+1,a+n+1));
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}

