// cfl422

// open on 9 : 35

// please eat heart by ultraing
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fir first
#define sec second
#define pb push_back
#define mkp make_pair
#define sz(s) (ll)(s.size())
#define all(v) v.begin(),v.end()
#define streps(i,s) for(auto i:s)
#define strep(i,s) for(int i=0;i<sz(s);i++)
#define fastread ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define release 1//交卷时一定要改成1 ,测试时小样例为0，大样例为2 
string filename="polygon";//题目名字 
string testcase="1";//测试组数 


const int mod=998244353,maxn=5002; 
int n,a[maxn];
void read(){
	#if release == 1 
	fastread;
	#endif
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
}
ll c[maxn<<1];
#define add(x,y) (x)=((x)+(y))%mod
void solve(){
	sort(a+1,a+n+1);
	ll ans=0;
	c[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			for(int j=a[i]+1;j<=10001;j++) add(ans,c[j]);
		}
		add(c[10001],c[10001]);
		for(int j=10000;j>=0;j--) add(c[min(j+a[i],10001)],c[j]);
	}
	cout<<ans<<endl;
}
signed main(){
	#if release == 2
	cin>>testcase;
	#endif
	#if release == 1
	freopen((filename+".in").c_str(),"r",stdin);
	freopen((filename+".out").c_str(),"w",stdout);
	#elif release == 2
	freopen((filename+testcase+".in").c_str(),"r",stdin);
	freopen((filename+".out").c_str(),"w",stdout);
	#endif
	read();
	solve();
//	#if release == 2
//	system(("start E:\\test\\checker.exe "+filename+testcase).c_str());
//	#endif
	return 0;
}

//不是这题让我想40分钟???
 
//检查一下每个题的release是否是1 
