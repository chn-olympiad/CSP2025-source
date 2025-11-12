/*??? string????*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define db double
#define i128 __int128
#define ull unsigned long long
#define ui unsigned int

const int N=5e6;
const int V=26*26;//=25*25=3125.
int n,q;
bool vis[N+10];
vector<int> a; 
const ll mod_1=1e9+7;
const ll mod_2=998244353;
const ll base=12200727;
const ll B=1e9;

map<ll,ll> mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s_1,s_2;
		cin>>s_1>>s_2;
		ll hsh_1=0,hsh_2=0;
		int n_2=(int)s_1.size();
		for(int j=0;j<n_2;j++){
			ll now=((s_1[j]-'a'+1)+(s_2[j]-'a'+1)*2880);
			hsh_1=(hsh_1*base+now)%mod_1;
			hsh_2=(hsh_2*base+now)%mod_2;
		}
		mp[hsh_1*B+hsh_2]++;
	}
	for(int i=1;i<=q;i++){
		string s_1,s_2;
		cin>>s_1>>s_2;
		if((int)s_1.size()!=(int)s_2.size()){
			cout<<0<<'\n';
			continue;
		}
		ll res=0;
		int n_2=(int)s_1.size();
		int L=-1,R=n_2;
		while(L+1<n_2&&s_1[L+1]==s_2[L+1]) L++;
		while(R-1>=0&&s_1[R-1]==s_2[R-1]) R--;
//		cout<<"debug:"<<L<<" "<<R<<'\n';
		
		for(int j=0;j<n_2;j++){
			ll hsh_1=0,hsh_2=0;
//			n_2=(int)s_1.size();
			for(int k=j;k<n_2;k++){
				ll now=((s_1[k]-'a'+1)+(s_2[k]-'a'+1)*2880);
				hsh_1=(hsh_1*base+now)%mod_1;
				hsh_2=(hsh_2*base+now)%mod_2;
				if(j<=L+1&&k>=R-1) res+=mp[hsh_1*B+hsh_2];
			}
		}
		cout<<res<<'\n';
	}
    return 0;
}
/*
W_C_brute [18:04,18:13]
C [,18:23]
fc replace.out replace1.ans
18:23 wait,query t_1!=t_2,so actully only need trie?

ulimit -s 1024000
g++ test.cpp -o test -std=c++14 -O2 -static -Wall -Wshadow -Wextra
g++ test.cpp -o test -std=c++14 -O2 -Wall -Wshadow -Wextra -fsanitize=address,undefined
./test 
*/