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
string filename="seat";//题目名字 
string testcase="4";//测试组数 


const int maxn=12,maxm=12;
int n,m,a[maxn*maxm];
int cj=0;
void read(){
	#if release == 1 
	fastread;
	#endif
	cin>>n;
	cin>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i],a[i]=-a[i];
	cj=a[1];
}
void solve(){
	sort(a+1,a+n*m+1);
	cj=lower_bound(a+1,a+n*m+1,cj)-a;
//	cout<<cj<<endl;
	int hang=1,lie=1;
	for(int i=1;i<cj;i++) {
		if(lie%2==1){
			if(hang==n) lie++;
			else hang++;
		}
		else{
			if(hang==1) lie++;
			else hang--;
		}
//		cout<<lie<<" "<<hang<<endl;
	}
	cout<<lie<<" "<<hang<<endl;
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
/*
2 2
99 100 97 98

2 2
98 99 100 97
*/
