#include<iostream>
#include<bitset>
#include<vector>
#include<string>
#define ll long long
using namespace std;

const int N=1e2+5;
const int p=998244353;

int n,m;

string str;
int s[N],c[N];

ll mem[10000005];

inline void getmn(int &a,int b){
	return a=(a<b?a:b),void();
}

inline void getmx(int &a,int b){
	return a=(a>b?a:b),void();
}

inline ll mul(ll a,ll b){
	return (a*b)%p;
}

inline ll jc(int x){
	if(mem[x])return mem[x];
	return mem[x]=mul(x,jc(x-1));
}

ll ans=0;
bitset<N>vis;

inline void dfs(vector<int>&v){
	if(v.size()==(unsigned)n+1){
		int cnt=0/*未录用人数*/,tot=0/*录用人数*/;
		for(int i=1;i<=n;++i){
			if(!s[i])++cnt;
			else{
				if(v[i]<=cnt)++cnt;
				else ++tot;
				if(tot>=m)return ++ans,void();
			}
		}
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue ;
		vis[i]=1,v.push_back(c[i]);
		dfs(v);
		vis[i]=0,v.pop_back();
	}
	return ;
}

inline void solve(){
	vector<int>v;v.push_back(0);
	dfs(v);
	return cout<<ans<<"\n",void();
}

signed main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	mem[0]=1;
	cin>>n>>m;cin>>str;
	int mn=1,mx=0;for(int i=1;i<=n;++i)s[i]=str[i-1]^48,getmn(mn,s[i]),getmx(mx,s[i]);
	for(int i=1;i<=n;++i)cin>>c[i];
	if(mn==1)return cout<<jc(n)<<"\n",0;
	if(m==1){
		if(!mx)return cout<<0<<"\n",0;
		else{
			int loc=1;
			for(int i=1;i<=n;++i){
				if(s[i]){
					loc=i;
					break ;
				}
			}
			int cnt=0;
			for(int i=1;i<=n;++i)if(c[i]>loc-1)++cnt;
			if(!cnt)return cout<<0<<"\n",0;
			return cout<<mul(cnt,jc(n-1))<<"\n",0;
		}
	}else if(m==n){
		return cout<<0<<"\n",0;
	}else solve();
	return 0;
}

/*
3 2
101
1 1 2

2

======


10 5
1101111011
6 0 4 2 1 2 5 4 3 3

2204128

*/