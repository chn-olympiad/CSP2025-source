#include<bits/stdc++.h>
#define N 200005
#define st first
#define nd second
using namespace std;
const int base=23,mod=1e9+9;
int n,q;
string s[N][3];
string t[3];
map<int,int> mp;
int cnt;
vector<pair<int,int>> v[N];
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.st<y.st or (x.st==y.st and x.nd<y.nd);
}
int maxn=0;
int h[N][3];
int pw[N];
int S[N][3];
int get(int l,int r,int op){
	if(l==0) return S[r][op];
	return (S[r][op]-1ll*S[l-1][op]*pw[r-l+1]%mod+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		maxn+=s[i][1].size()+s[i][2].size();
	}
	if(maxn<=5000){
		pw[0]=1;
		for(int i=1;i<=5000;i++){
			pw[i]=1ll*pw[i-1]*base%mod;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<s[i][1].size();j++){
				h[i][1]=(1ll*h[i][1]*base%mod+(s[i][1][j]-'a'+1))%mod;
			}
			for(int j=0;j<s[i][2].size();j++){
				h[i][2]=(1ll*h[i][2]*base%mod+(s[i][2][j]-'a'+1))%mod;
			}
		}
		while(q--){
			int ans=0;
			cin>>t[1]>>t[2];
			S[0][1]=t[1][0]-'a'+1;
			for(int j=1;j<t[1].size();j++){
				S[j][1]=(1ll*S[j-1][1]*base+t[1][j]-'a'+1)%mod;
			}
			S[0][2]=t[2][0]-'a'+1;
			for(int j=1;j<t[2].size();j++){
				S[j][2]=(1ll*S[j-1][2]*base+t[2][j]-'a'+1)%mod;
			}
			int r;
			for(int i=t[1].size()-1;i>=0;i--){
				r=i;
				if(get(i,t[1].size()-1,1)!=get(i,t[1].size()-1,2)) break;
			}
			for(int i=0;i<t[1].size();i++){
				for(int j=1;j<=n;j++){
					int len=s[j][1].size();
					if(i+len-1<t[1].size() and i+len-1>=r and get(i,i+len-1,1)==h[j][1] and get(i,i+len-1,2)==h[j][2]) ans++;
				}
				if(get(0,i,1)!=get(0,i,2)) break;
			}
			cout<<ans<<'\n';
		}
	}
	else{
		for(int i=1;i<=n;i++){
			int x,y;
			for(int j=0;j<s[i][1].size();j++){
				if(s[i][1][j]=='b'){
					x=j;
					break;
				}
			}
			for(int j=0;j<s[i][2].size();j++){
				if(s[i][2][j]=='b'){
					y=j;
					break;
				}
			}	
			if(mp[y-x]==0){
				mp[y-x]=++cnt;
			}
			v[mp[y-x]].push_back({s[i][1].size()-x,x});
		}
		for(int i=1;i<=cnt;i++) sort(v[i].begin(),v[i].end(),cmp);
		for(int i=1;i<=q;i++){
			cin>>t[1]>>t[2];
			int x,y;
			for(int j=0;j<t[1].size();j++){
				if(t[1][j]=='b'){
					x=j;
					break;
				}
			}
			for(int j=0;j<t[2].size();j++){
				if(t[2][j]=='b'){
					y=j;
					break;
				}
			}	
			if(mp.find(y-x)==mp.end()){
				cout<<0<<'\n';
				continue;
			}
			else{
				int ans=0;
				int p=mp[y-x];
				for(auto i:v[p]){
					if(i.st>t[1].size()-x) break;
					if(i.nd<=x) ans++;
				}
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}