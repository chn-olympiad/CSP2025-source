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

const int N=2e5+5,M=5e6+5;
int n,q,len[N];
string s[N][3],t[3];

namespace Hash1{
	const int base=27,Mod=1e9+7;
	vi has[N*2+5];
	int pw[M];
	void init(){
		pw[0]=1;
		for(int i=1;i<=M-5;i++){
			pw[i]=(LL)pw[i-1]*base%Mod;
		}
	}
	void make(int i,string s){
		int n=s.size();
		s=" "+s;
		has[i].resize(n+2);
		for(int j=1;j<=n;j++){
			has[i][j]=((LL)has[i][j-1]*base%Mod+(s[j]-'a'+1))%Mod;
		}
	}
	int get(int i,int l,int r){
		return (has[i][r]-(LL)has[i][l-1]*pw[r-l+1]%Mod+Mod)%Mod;
	}
}
namespace Hash2{
	const int base=131,Mod=998244353;
	vi has[N*2+5];
	int pw[M];
	void init(){
		pw[0]=1;
		for(int i=1;i<=M-5;i++){
			pw[i]=(LL)pw[i-1]*base%Mod;
		}
	}
	void make(int i,string s){
		int n=s.size();
		s=" "+s;
		has[i].resize(n+2);
		for(int j=1;j<=n;j++){
			has[i][j]=((LL)has[i][j-1]*base%Mod+(s[j]-'a'+1))%Mod;
		}
	}
	int get(int i,int l,int r){
		return (has[i][r]-(LL)has[i][l-1]*pw[r-l+1]%Mod+Mod)%Mod;
	}
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	Hash1::init();
	Hash2::init();
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		Hash1::make(i*2-1,s[i][0]);
		Hash1::make(i*2,s[i][1]);
		Hash2::make(i*2-1,s[i][0]);
		Hash2::make(i*2,s[i][1]);
		len[i]=s[i][0].size();
		s[i][0]=" "+s[i][0];
		s[i][1]=" "+s[i][1];
	}
	while(q--){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<"0\n";
			continue;
		}
		Hash1::make(n*2+1,t[0]);
		Hash1::make(n*2+2,t[1]);
		Hash2::make(n*2+1,t[0]);
		Hash2::make(n*2+2,t[1]);
		int ln=t[0].size(),ans=0,l=ln+1,r=0;
		t[0]=" "+t[0],t[1]=" "+t[1];
		for(int i=1;i<=ln;i++){
			if(t[0][i]!=t[1][i]){
				tmin(l,i),tmax(r,i);
			}
		}
		for(int i=1;i<=n;i++){
			if(len[i]>ln||len[i]<r-l+1) continue;
			bool flag0=0,flag1=0;
			for(int j=max(1,r+1-len[i]);j+len[i]-1<=ln&&j<=l;j++){
				if(Hash1::get(2*i-1,1,len[i])==Hash1::get(n*2+1,j,j+len[i]-1)&&Hash2::get(2*i-1,1,len[i])==Hash2::get(n*2+1,j,j+len[i]-1)){
					flag0=1;
					break;
				}
			}
			for(int j=max(1,r+1-len[i]);j+len[i]-1<=ln&&j<=l;j++){
				if(Hash1::get(2*i,1,len[i])==Hash1::get(n*2+2,j,j+len[i]-1)&&Hash2::get(2*i,1,len[i])==Hash2::get(n*2+2,j,j+len[i]-1)){
					flag1=1;
					break;
				}
			}
//			cout<<i<<" "<<flag0<<" "<<flag1<<"\n";
			if(flag0&&flag1){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

