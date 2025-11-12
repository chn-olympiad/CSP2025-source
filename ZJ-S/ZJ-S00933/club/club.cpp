#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s[100005][5],t,b[100005],c[100005],ans=0;
struct node{
	int u,yuan,nxt;
	bool operator <(const node& k)const{
		return s[u][yuan]-s[u][nxt] > s[k.u][k.yuan]-s[k.u][k.nxt];
	}
};
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		priority_queue<node>fr,se,tr;
		memset(s,0,sizeof(s));
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&s[i][0],&s[i][1],&s[i][2]);
		}
		for(int i=1;i<=n;i++){
			if(s[i][0]>=s[i][1]&&s[i][1]>=s[i][2]){
				fr.push(node({i,0,1}));
			}
			else if(s[i][0]>=s[i][2]&&s[i][2]>=s[i][1]){
				fr.push(node({i,0,2}));
			}
			else if(s[i][1]>=s[i][0]&&s[i][0]>=s[i][2]){
				se.push(node({i,1,0}));
			}
			else if(s[i][1]>=s[i][2]&&s[i][2]>=s[i][0]){
				se.push(node({i,1,2}));
			}
			else if(s[i][2]>=s[i][1]&&s[i][1]>=s[i][0]){
				tr.push(node({i,2,1}));
			}
			else if(s[i][2]>=s[i][0]&&s[i][0]>=s[i][1]){
				tr.push(node({i,2,0}));
			}
		}
		
		while(fr.size()>n/2){
			ans+=s[fr.top().u][fr.top().nxt];
			fr.pop();
		}
		while(se.size()>n/2){
			ans+=s[se.top().u][se.top().nxt];
			se.pop();
		}
		while(tr.size()>n/2){
			ans+=s[tr.top().u][tr.top().nxt];
			tr.pop();
		}
		while(!fr.empty()){
			ans+=s[fr.top().u][0];
			fr.pop();
		}
		while(!se.empty()){
			ans+=s[se.top().u][1];
			se.pop();
		}
		while(!tr.empty()){
			ans+=s[tr.top().u][2];
			tr.pop();
		}
		printf("%lld\n",ans);
	}
	return 0;
}

