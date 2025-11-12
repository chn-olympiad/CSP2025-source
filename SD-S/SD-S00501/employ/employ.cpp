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

const int N=5e2+5,Mod=998244353;
int n,m,c[N];
string str;

namespace sub1{
	const int M=(1<<18)+5,NN=18+5;
	vi state[NN];
	int dp[M][NN];
	void solve(){
		for(int s=0;s<(1<<n);s++){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(s>>(i-1)&1){
					cnt++;
				}
			}
			state[cnt].pb(s);
		}
		dp[0][0]=1;
		for(int o=0;o<n;o++){
			for(auto s:state[o]){
				for(int i=0;i<=o;i++){
					for(int j=1;j<=n;j++){
						if(~s>>(j-1)&1){
							int ns=s|(1<<(j-1)),ni=i;
							if(o-i<c[j]&&str[o+1]=='1'){
								ni++;
							}
							dp[ns][ni]=(dp[ns][ni]+dp[s][i])%Mod;
						}
					}
//					cout<<s<<" "<<i<<":"<<dp[s][i]<<"\n";
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++){
			ans+=dp[(1<<n)-1][i];
//			cout<<(1<<n)-1<<" "<<i<<":"<<dp[(1<<n)-1][i]<<"\n";
		}
		cout<<ans;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>str;
	str=" "+str;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sub1::solve();
	return 0;
}

