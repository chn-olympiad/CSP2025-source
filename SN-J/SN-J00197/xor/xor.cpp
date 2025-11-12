// cfl422
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
string filename="xor";//题目名字 
string testcase="3";//测试组数 


const int maxn=5e5+202,maxm=1.2e6+2;
int n,k,a[maxn],ge[maxm];
void read(){
	#if release == 1 
	fastread;
	#endif
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
}
void solve(){
	for(int i=1;i<=(1<<20);i++) ge[i]=-1;
	ge[0]=0;
	int las=0;
	int xorsum=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		xorsum^=a[i];
		if(ge[xorsum^k]>=las) {
			cnt++;
			ge[xorsum^k]=0;
			las=i;
//			cout<<i<<" "<<endl;
		}
		ge[xorsum]=i;
	}
	cout<<cnt<<endl;
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
/*
4 2
2 1 0 3
4 3
2 1 0 3
4 0
2 1 0 3
*/
