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
#define release 1  //交卷时一定要改成1，测sample时改为2，控制台交互时改为0
string filename="replace";   //改为当前文件名 ! ! ! ! !
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

const int maxn=2e5+202,maxq=2e5+202,maxstring=5e6+202,mod=1e9+7;
int n,q;
string s1[maxn],s2[maxn];
ll po29[maxstring],inv[maxstring];
ll power(ll x,ll y){
	ll ret=1;
	while(y){
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
		y>>=1; 
	}
	return ret;
}
//#define DEBUG
struct Hash{
	vector<ll> a;
	ll& operator[](const int pos){return a[pos];}
	void set(string& s){
		if(s[0]!=' ') s=s+" ";
		a.resize(sz(s)+1);
		a[0]=0;
		for(int i=1;i<sz(s);i++){
			a[i]=(a[i-1]+po29[i]*(s[i]-'a'+1))%mod;
		}
	}
	Hash(){
		a.resize(1);
		a[0]=0;
	}
	Hash(string& s){
		set(s);
	}
	ll get(int l,int r){
		return (a[r]-a[l-1]+mod)%mod*inv[l-1]%mod;
	}
};
Hash hs1[maxn],hs2[maxn];
int l[maxn],r[maxn];
ll hs[maxn][2];
void solve(){
	#if release == 1 || release == 2
	fastread;
	#endif
	po29[0]=1;
	for(int i=1;i<=5e6;i++) po29[i]=po29[i-1]*29%mod;
	inv[(int)(5e6)]=power(po29[(int)(5e6)],mod-2);
	for(int i=5e6-1;i>=0;i--) inv[i]=(inv[i+1]*29)%mod;
	#ifdef DEBUG
//	cout<<inv[0]<<endl;
	#endif
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],s1[i]=" "+s1[i],s2[i]=" "+s2[i];
	for(int i=1;i<=n;i++) hs1[i].set(s1[i]),hs2[i].set(s2[i]);
	for(int j=1;j<=n;j++){
		l[j]=1,r[j]=sz(s1[j]);
		for(int i=1;i<sz(s1[j]);i++)
			if(s1[j][i]!=s2[j][i]){
				l[j]=i;
				break;
			}
		for(int i=sz(s1[j])-1;i>=1;i--)
			if(s1[j][i]!=s2[j][i]){
				r[j]=i;
				break;
			}
		hs[j][0]=hs1[j].get(l[j],r[j]);
		hs[j][1]=hs2[j].get(l[j],r[j]);
		#ifdef DEBUG
		cout<<l[j]<<" "<<r[j]<<endl;
		#endif
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(sz(t1)!=sz(t2)){
			cout<<0<<endl;
			continue;
		}
		t1=" "+t1;
		t2=" "+t2;
		int l1=1,r1=sz(t1);
		for(int i=1;i<sz(t1);i++)
			if(t1[i]!=t2[i]){
				l1=i;
				break;
			}
		for(int i=sz(t1)-1;i>=1;i--)
			if(t1[i]!=t2[i]){
				r1=i;
				break;
			}
			#ifdef DEBUG
//			cout<<l1<<" "<<r1<<endl;
			#endif
		int len=r1-l1+1;
		Hash h1(t1),h2(t2);
		ll h[2]={h1.get(l1,r1),h2.get(l1,r1)}; 
		int ans=0;
		for(int i=1;i<=n;i++){
			int len2=r[i]-l[i]+1;
			#ifdef DEBUG
			cout<<i<<" "<<len<<" "<<len2<<" "<<h[0]<< " "<<hs[i][0]<<" "<<h[1]<<" "<<hs[i][1]<<endl;
			#endif
			if(len==len2&&h[0]==hs[i][0]&&h[1]==hs[i][1]){
				#ifdef DEBUG
				cout<<"!"<<endl;
				cout<<l[i]-1<<" "<<l1-l[i]+1<<" "<<l1-1<<" "<<r[i]+1<<" "<<sz(s1[i])-1<<" "<<r1+1<<" "<<(sz(s1[i])-1)-r[i]+r1<<endl;
				#endif
				if(l[i]<=l1&&sz(s1[i])-r[i]<=sz(t1)-r1&&
				hs1[i].get(1,l[i]-1)==h1.get(l1-l[i]+1,l1-1)&&hs1[i].get(r[i]+1,sz(s1[i])-1)==h1.get(r1+1,(sz(s1[i])-1)-r[i]+r1)&&
				hs2[i].get(1,l[i]-1)==h2.get(l1-l[i]+1,l1-1)&&hs2[i].get(r[i]+1,sz(s2[i])-1)==h2.get(r1+1,(sz(s1[i])-1)-r[i]+r1)
				){
					#ifdef DEBUG
					cout<<" "<<i<<endl; 
					#endif
					ans++;
				}
			}
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





















// celeste
