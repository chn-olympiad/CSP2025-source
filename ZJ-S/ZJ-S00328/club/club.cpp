#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
struct node{
	int a,b,c,d;
	bool friend operator<(node a,node b){
		return a.d<b.d;
	}
}w[100005];
vector<node>tmp[3],now;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&w[i].a,&w[i].b,&w[i].c);
	ll sum=0;tmp[0].clear(),tmp[1].clear(),tmp[2].clear();
	for(int i=1;i<=n;i++){
		sum+=1ll*max(max(w[i].a,w[i].b),w[i].c);
		if(w[i].a>=w[i].b&&w[i].a>=w[i].c){
			w[i].d=max(w[i].b,w[i].c)-w[i].a;
			tmp[0].emplace_back(w[i]);
		}
		else if(w[i].b>=w[i].c){
			w[i].d=max(w[i].a,w[i].c)-w[i].b;
			tmp[1].emplace_back(w[i]);
		}
		else w[i].d=max(w[i].a,w[i].b)-w[i].c,tmp[2].emplace_back(w[i]);
	}
	if((int)tmp[0].size()<=n/2&&(int)tmp[1].size()<=n/2&&(int)tmp[2].size()<=n/2){
		printf("%lld\n",sum);return;
	}
	if((int)tmp[0].size()>n/2)now=tmp[0];
	else if((int)tmp[1].size()>n/2)now=tmp[1];
	else if((int)tmp[2].size()>n/2)now=tmp[2];
	sort(now.begin(),now.end());
	while((int)now.size()>n/2)sum+=now.back().d,now.pop_back();
	now.clear();
	printf("%lld\n",sum);
}
signed main(){
	//system("fc club.out std.out");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)solve();
}