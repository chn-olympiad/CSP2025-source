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
string filename="number";//题目名字 
string testcase="4";//测试组数 


string s;
int ge[10];
void read(){
	#if release == 1 
	fastread;
	#endif
	cin>>s;
}
void solve(){
	streps(i,s) if(i>='0'&&i<='9') ge[i-'0']++;
//	for(int i=0;i<=9;i++) cout<<ge[i]<<endl;
	for(int i=9;i>=0;i--) for(int j=1;j<=ge[i];j++) cout<<i;
	cout<<endl;
}
signed main(){
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
