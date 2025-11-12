#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+5;
int n;
struct node{
	int c[3];
	int tag,s,ch;
}a[N];
struct infor{
	int id,ch;
	bool operator<(const infor &o)const{
		return ch<o.ch;
	}
};
vector<infor> cl[3];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cl[0].clear(),cl[1].clear(),cl[2].clear();
		memset(a,0,sizeof a);
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].c[0]>>a[i].c[1]>>a[i].c[2];
		for(int i=1;i<=n;i++){
			int mx=max(a[i].c[0],max(a[i].c[1],a[i].c[2]));
			if(a[i].c[0]==mx){
				a[i].tag=0;
				a[i].s=(a[i].c[1]>a[i].c[2]?1:2);
				a[i].ch=a[i].c[a[i].tag]-a[i].c[a[i].s];
			}else if(a[i].c[1]==mx){
				a[i].tag=1;
				a[i].s=(a[i].c[0]>a[i].c[2]?0:2);
				a[i].ch=a[i].c[a[i].tag]-a[i].c[a[i].s];
			}else{
				a[i].tag=2;
				a[i].s=(a[i].c[0]>a[i].c[1]?0:1);
				a[i].ch=a[i].c[a[i].tag]-a[i].c[a[i].s];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			infor ip;
			ip.id=i,ip.ch=a[i].ch;
			cl[a[i].tag].push_back(ip);
			ans+=a[i].c[a[i].tag];
		}
		int ove=-1,os=0;
		for(int i=0;i<3;i++){
			if(cl[i].size()>n/2){
				ove=i;
				os=cl[i].size()-n/2;
				break;
			}
		}
		if(ove==-1){
			cout<<ans<<'\n';
			continue;
		}
		sort(cl[ove].begin(),cl[ove].end());
		for(int i=0;i<os;i++)ans-=cl[ove][i].ch;
		cout<<ans<<'\n';
	}
	return 0;
}
