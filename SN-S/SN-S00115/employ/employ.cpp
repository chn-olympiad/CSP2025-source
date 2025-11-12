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
string filename="employ";   //改为当前文件名 ! ! ! ! !
string testcase;

/*
注意fc时如果找不到文件，检查一下filename的值 
*/
#define is_digit(x) (((x)>='0')&&((x)<='9'))
inline ll rd(){
	ll ret=0;
	int flag=1;
	char c=getchar();
	while(!is_digit(c)&&c!='-') c=getchar();
	if(c=='-'){
		flag=-1;
		c=getchar();
	}
	while(is_digit(c)){
		ret=ret*10+(c-'0');
		c=getchar();
	}
//	cout<<ret*flag<<endl;
	return ret*flag;
}
const int maxn=502,mod=998244353;
int n,m;
char s[maxn];
int c[maxn];
void solve(){
	#if release == 1
	fastread;
	#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	int ans=0;
	do{
		int kong=0;
		for(int i=1;i<=n;i++){
//			cout<<c[i]<<" ";
			if(s[i]=='0'||kong>=c[i]){
				kong++;
			}
		}
//		cout<<endl;
		ans+=(kong<=n-m);
	}while(next_permutation(c+1,c+n+1));
	cout<<ans<<endl;
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
