#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int INF=1e5+10;
struct Node{
	int a,b,c,id;
}s[INF];
long long ans;
struct Pair{
	int id,c;
	bool operator <(const Pair a1)const{
		return a1.c<c;
	}
};
priority_queue<Pair> q[3];

inline void init(){
	ans=0;
	for (int i=0;i<3;i++)while (!q[i].empty())q[i].pop();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while (T--){
		int n;cin>>n;
		init();
		for (int i=1;i<=n;i++){
			int t[4];
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].id=i;
			t[1]=s[i].a,t[2]=s[i].b,t[3]=s[i].c;
			sort(t+1,t+1+3);
			int maxn=t[3],mn_maxn=t[2];
			ans+=maxn;
//			cout<<maxn-mn_maxn<<"\n";
			if (maxn==s[i].a)q[0].push({i,maxn-mn_maxn});
			else if (maxn==s[i].b)q[1].push({i,maxn-mn_maxn});
			else q[2].push({i,maxn-mn_maxn});
		}
		while ((int)q[0].size()>n/2){
			int c=q[0].top().c;
		//	cout<<1<<" "<<q[0].top().id<<" "<<c<<"\n";
			q[0].pop();
			ans-=c;
//			int t[4];t[1]=s[id].a,t[2]=s[id].b,t[3]=s[id].c;
//			sort(t+1,t+1+3);
//			int 
		}
		while ((int)q[1].size()>n/2){
			int c=q[1].top().c;
//			cout<<2<<" "<<q[1].top().id<<" "<<c<<"\n";
			q[1].pop();
			ans-=c;
		}
		while ((int)q[2].size()>n/2){
			int c=q[2].top().c;
//			cout<<3<<" "<<q[2].top().id<<" "<<c<<"\n";
			q[2].pop();
			ans-=c;
		}  
		cout<<ans<<"\n";
	}
	return 0;
}
