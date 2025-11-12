#include <bits/stdc++.h>
using namespace std;
// #define int long long 
// #define inf 0x3f3f3f3f3f3f3f3fll
#define For(i,l,r) for(int i=(l);i<=(r);++i)
#define Rof(i,l,r) for(int i=(l);i>=(r);--i)
namespace cjr2010{
	template<typename ta,typename tb>
	void MIN(ta &a,tb b){if(a>b) a=b;}
	template<typename ta,typename tb>
	void MAX(ta &a,tb b){if(a<b) a=b;}
	const int N=200005;
	const int M=5000005;
	int n,q,ns[N];
	string s[N][2],t[2];
	int a[N][2],b[2];
	struct ACAM{
		int tr[M][27],TR[M],id;
		void ins(string s){
			int p=0;
			for(char i:s){
				int t=i-'`';
				if(!tr[p][t]) tr[p][t]=++id;
				p=tr[p][t];
			}
			TR[p]++;
		}
		int fa[M];
		queue<int> q;
		void build(){
			fa[0]=0;
			For(i,0,26) if(tr[0][i]) fa[tr[0][i]]=0,q.push(tr[0][i]);
			while(!q.empty()){
				int u=q.front();q.pop();
				TR[u]+=TR[fa[u]];
				For(i,0,26){
					if(tr[u][i]) fa[tr[u][i]]=tr[fa[u]][i],q.push(tr[u][i]);
					else tr[u][i]=tr[fa[u]][i];
				}
			}
		}
	}acam;
	void MAIN(){
		// acam data
		// cout<<1<<" "<<1<<"\n";
		// For(i,1,250000) cout<<"a";
		// cout<<" ";
		// For(i,1,250000) cout<<"b";
		// cout<<"\n";
		// For(i,1,250000) cout<<"a";
		// cout<<" ";
		// For(i,1,250000) cout<<"b";
		// cout<<"\n";
		// return ;
		cin>>n>>q;
		For(i,1,n){
			cin>>s[i][0]>>s[i][1];
			ns[i]=s[i][0].size();
			a[i][0]=-1;while(a[i][0]+1<ns[i]&&s[i][0][a[i][0]+1]==s[i][1][a[i][0]+1]) a[i][0]++;
			a[i][1]=ns[i];while(a[i][1]-1>=0&&s[i][0][a[i][1]-1]==s[i][1][a[i][1]-1]) a[i][1]--;
			if(s[i][0]==s[i][1]) continue;
			string tmp="";
			For(j,0,a[i][0]) tmp+=s[i][0][j];
			tmp+='`';
			For(j,a[i][0]+1,a[i][1]-1) tmp+=s[i][0][j];
			For(j,a[i][0]+1,a[i][1]-1) tmp+=s[i][1][j];
			tmp+='`';
			For(j,a[i][1],ns[i]-1) tmp+=s[i][0][j];
			acam.ins(tmp);
		}
		acam.build();
		For(i,1,q){
			cin>>t[0]>>t[1];
			if(t[0].size()!=t[1].size()){
				cout<<"0\n";
				continue;
			}
			int nt=t[0].size();
			b[0]=-1;while(b[0]+1<nt&&t[0][b[0]+1]==t[1][b[0]+1]) b[0]++;
			b[1]=nt;while(b[1]-1>=0&&t[0][b[1]-1]==t[1][b[1]-1]) b[1]--;
			string tmp="";
			For(j,0,b[0]) tmp+=t[0][j];
			tmp+='`';
			For(j,b[0]+1,b[1]-1) tmp+=t[0][j];
			For(j,b[0]+1,b[1]-1) tmp+=t[1][j];
			tmp+='`';
			For(j,b[1],nt-1) tmp+=t[0][j];
			int p=0,ans=0;
			for(char j:tmp){
				p=acam.tr[p][j-'`'];
				ans+=acam.TR[p];
			}
			cout<<ans<<"\n";
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);cjr2010::MAIN();
	return 0;
}