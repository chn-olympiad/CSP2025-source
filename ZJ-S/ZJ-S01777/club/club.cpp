#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
#define fst first
#define scd second
#define llg long long
#define pii pair<int,int>
#define mkp make_pair
const pii Nul={0,0};
int n;
pii f[N][3];
multiset<int> s[4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin>>T;
	while(T--){
		cin>>n; llg ans=0;
		for(int j=1; j<=3; j++) s[j].clear();
		for(int i=1; i<=n; i++){
			for(int j=1; j<=3; j++)
				cin>>f[i][j].fst,f[i][j].scd=j;
			pair<pii,pii > cur=mkp(Nul,Nul);
			for(int j=1; j<=3; j++){
				cur.scd=max(cur.scd,f[i][j]);
				if(cur.fst<cur.scd) swap(cur.fst,cur.scd);
			}
			ans+=cur.fst.fst;
			s[cur.fst.scd].insert(cur.fst.fst-cur.scd.fst);
		}
		int pos=0;
//		for(int j=1; j<=3; j++,cout<<"\n")
//			for(auto x : s[j]) cout<<x<<" ";
		for(int j=1; j<=3; j++)
			if(s[j].size()>s[pos].size()) pos=j;
		if(s[pos].size()*2>n){
			int num=s[pos].size()-(n/2);
		//	cout<<num<<"!\n";
			for(auto it=s[pos].begin(); it!=s[pos].end()&&num; num--,it++){
				ans-=(*it);
			}
		}
		cout<<ans<<"\n";
	}
}
