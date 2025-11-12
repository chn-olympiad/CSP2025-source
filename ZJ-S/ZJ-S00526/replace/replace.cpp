#include <bits/stdc++.h>
#define int long long
#define unint unsigned long long
using namespace std;
const int N=2e5+10,M=5e6+10;
unint hsa[N],hsb[N],hs[2][M],pw[M];
vector<int> v[35];
bool vis[N];
int siz[N];
int dp[M];
void init_hash(string &x,int p,int id){
	pw[0]=1;
	int len=x.size();
	x=" "+x;
	for(int i=1;i<=len;i++){
		hs[id][i]=hs[id][i-1]*p+x[i]-'a';
		pw[i]=pw[i-1]*p;
	}
	return ;
}
unint get_hash(int l,int r,int id){
	unint ans=hs[id][r]-hs[id][l-1]*pw[r-l+1];
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q,p=13331;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		siz[i]=a.size();
		for(int j=0;j<a.size();j++){
			hsa[i]=hsa[i]*p+a[j]-'a';
		}
		for(int j=0;j<b.size();j++){
			hsb[i]=hsb[i]*p+b[j]-'a';
		}
		v[a[siz[i]-1]-'a'].push_back(i);
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int len=a.size();
		init_hash(a,p,0);
		init_hash(b,p,1);
		if(a.size()!=b.size()){
			cout<<0<<"\n";
			continue;
		}
		memset(dp,0,sizeof dp);
		memset(vis,0,sizeof vis);
		dp[0]=1;
		for(int i=1;i<=len;i++){
			if(a[i]==b[i]){
				dp[i]=dp[i-1];
			}
			for(int kk=0;kk<v[a[i]-'a'].size();kk++){
				int j=v[a[i]-'a'][kk];
				if(i>=siz[j]&&hsa[j]==get_hash(i-siz[j]+1,i,0)&&hsb[j]==get_hash(i-siz[j]+1,i,1)&&!vis[j]){
					vis[j]=1;
					dp[i]+=dp[i-siz[j]];
				}
			}
		}
		cout<<dp[len]<<"\n";
	}
	return 0;
}
