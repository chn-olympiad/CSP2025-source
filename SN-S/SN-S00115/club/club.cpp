// cfl 422 

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define fir first
#define sec second
#define mkp make_pair
#define sz(s) (int)(s.size())
#define all(v) v.begin(),v.end()
#define strep(i,s) for(int i=0;i<sz(s);i++)
#define streps(i,s) for(auto i:s)
#define fastread ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define Min(x,y) x=min((x),(y))
#define Max(x,y) x=max((x),(y))
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define release 1   //交卷时一定要改成1，测sample时改为2，控制台交互时改为0
string filename="club";   //改为当前文件名 ! ! ! ! !
string testcase;

/*
注意fc时如果找不到文件，检查一下filename的值 
*/
const int maxn=1e5+202;
int aqx,n;
struct CLUB{
	int a[4];
}a[maxn];
int ge[4];
priority_queue<int> q[4];
void solve(){
	#if release == 1
	fastread;
	#endif
	cin>>aqx;
	while(aqx--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3];
		memset(ge,0,sizeof(ge));
		for(int i=1;i<=3;i++) while(!q[i].empty()) q[i].pop();
		ll ans=0;
		for(int i=1;i<=n;i++){
			int mx=-1,mxi=0;
			for(int j=1;j<=3;j++)
				if(a[i].a[j]>mx){
					mx=a[i].a[j];
					mxi=j;
				}
			int ss=-0x3f3f3f3f;
			for(int j=1;j<=3;j++)
				if(j!=mxi)
					Max(ss,a[i].a[j]-mx);
			q[mxi].push(ss);
			ans+=mx; 
			if(ge[mxi]>=(n>>1)){
				ans+=q[mxi].top();
				q[mxi].pop();
			}
			else ge[mxi]++;
		}
		cout<<ans<<endl;
	}
}
signed main(){
	#if release == 1
	freopen((filename+".in").c_str(),"r",stdin);
	freopen((filename+".out").c_str(),"w",stdout);
	#elif release ==2
	cin>>testcase;
	freopen((filename+testcase+".in").c_str(),"r",stdin);
	freopen((filename+".out").c_str(),"w",stdout);
	#endif
	solve();
	return 0;
}

























































































































// absyyyy121
