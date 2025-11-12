#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define umap unordered_map
#define m(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+10,pw=31,mod=1e9+7;
int n,m,k,T,a[N],bas[N],q,sumL;
struct node{int a,b,len;}e[N];
int q1[N],q2[N],cnt;
vector<pair<int,int> > g[N];
umap<int,int> mp;
int inline idx(int x){
	if(mp[x]==0) mp[x]=++cnt;
	return mp[x];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;bas[0]=1;
    rep(i,1,N-1) bas[i]=bas[i-1]*pw%mod;
    rep(i,1,n){
			string s1,s2;cin>>s1>>s2;
			int len=s1.size(),x=0,y=0;sumL+=len;
			rep(j,0,len-1){
				if(s1[j]=='b'){
					x=j;
				}if(s2[j]=='b'){
					y=j;
				}
			}g[idx(x-y)].pb({len-x,x});
			int w1=0,w2=0;
	    	rep(j,0,len-1){
	    		w1=(w1*pw+(s1[j]-'a'+1))%mod;
	    		w2=(w2*pw+(s2[j]-'a'+1))%mod;
			}e[i]={w1,w2,len};
		}
    if(n<=1010&&sumL<=2000){
	    rep(i,1,q){
			int ans=0;
			string s1,s2;cin>>s1>>s2;
		    if(s1.size()!=s2.size()){
		    	cout<<0<<'\n';continue;
			}int len=s2.size();s1=" "+s1;s2=" "+s2;
	        rep(j,1,len){
	    	    q1[j]=(q1[j-1]*pw+(s1[j]-'a'+1))%mod;
	    	    q2[j]=(q2[j-1]*pw+(s2[j]-'a'+1))%mod;
			}rep(j,1,n){
				int l2=e[j].len;
				rep(k,1,len-l2+1){
					int x3=q1[k-1];
				    int x=((q1[k+l2-1]-q1[k-1]*bas[l2]%mod)%mod+mod)%mod;
				    int y=((q1[len]-q1[l2+k-1]*bas[len-(l2+k-1)]%mod)%mod+mod)%mod;
				    if(x==e[j].a){
					    if((x3*bas[len-k+1]%mod+e[j].b*bas[len-(l2+k-1)]%mod+y)%mod==q2[len]){
					    	ans++;
						}
					}
				}
			}cout<<ans<<'\n'; 
		}
	}else{
		rep(i,1,cnt){
			sort(g[i].begin(),g[i].end());
		}rep(i,1,q){
		    string s1,s2;cin>>s1>>s2;
			int len=s1.size(),x=0,y=0;
			rep(j,0,len-1){
				if(s1[j]=='b'){
					x=j;
				}if(s2[j]=='b'){
					y=j;
				}
			}if(s1.size()!=s2.size()){
				cout<<0<<'\n';continue;
			}int w=len-x,bt=idx(x-y);
			int ans=0;
			for(pair<int,int> t:g[bt]){
				if(t.fi>w) break;
				if(t.se<=x) ans++;
			}cout<<ans<<'\n';
		}
	}
	return 0;
}
