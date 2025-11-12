#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
struct node{
	int val,x,cval;
	bool operator<(const node &rhs)const{
		return val-cval>rhs.val-rhs.cval;
	}
};
priority_queue<node>pq[4];//Ð¡¸ù¶Ñ 
int n;
pii a[200010][5];
bool cmp(pii x,pii y){
	if(x.first==y.first)return x.second<y.second;
	return x.first>y.first;
}
void in(int i,int m){
	int val=a[i][m].first,x=a[i][m].second;
	int cval=a[i][m+1].first,cx=a[i][m+1].second;
	if(pq[x].size()<n/2){
		pq[x].push((node){val,i,cval});
		return;
	}
	node y=pq[x].top();
	if(y.val+cval>=val+y.cval){
		pq[cx].push((node){cval,i,a[i][m+2].first});
		return;
	}
	pq[x].pop();
	pq[x].push((node){val,i,cval});
	in(y.x,2);
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][1].first,&a[i][2].first,&a[i][3].first);
		a[i][1].second=1,a[i][2].second=2,a[i][3].second=3;
		sort(a[i]+1,a[i]+4,cmp);	
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i][1].first<<" "<<a[i][2].first<<" "<<a[i][3].first<<endl;
//	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		in(i,1);
	} 
	for(int i=1;i<=3;i++){
		while(!pq[i].empty())ans+=pq[i].top().val,pq[i].pop();
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
/*
int v=pq[x].top().val,y=pq[x].top().x;
			if(val+pq[x].top().cval<=v+a[i][2].first){
				pq[a[i][2].second].push({a[i][2].first,i,a[i][3].first});
			}else{
				while(pq[x].size()&&val+pq[x].top().cval>v+a[i][2].first){
					pq[x].pop();
					pq[a[y][2].second].push({a[y][2].first,y,a[y][3].first});
					v=pq[x].top().val,y=pq[x].top().x;
				}
				pq[x].push({val,i,a[i][2].first});
			}
*/ 
