#include<stdio.h>
#include<algorithm>
#include<queue>
#include<map>
#define rep(i,s,e) for(int i=(s);i<=(e);++i)
#define _rep(i,s,e) for(int i=(s);i<(e);++i)
#define rev(i,s,e) for(int i=(s);i>=(e);--i)

const int N=1e5+10;

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}
template<typename T>
void swap(T& x,T& y){T t=x;x=y,y=t;}

std::priority_queue<int,std::vector<int>,std::greater<int> >q[3];

struct node{
	int v,id;
};

int n;

void solve() {
	int ans=0;
	scanf("%d",&n);
	rep(i,1,n) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		node t[3]={{x,0},{y,1},{z,2}};
		if(t[0].v>t[1].v) swap(t[0],t[1]);
		if(t[1].v>t[2].v) swap(t[1],t[2]);
		if(t[0].v>t[1].v) swap(t[0],t[1]);
		if(q[t[2].id].size()<n/2) ans+=t[2].v,q[t[2].id].push(t[2].v-t[1].v);
		else {
			if(q[t[2].id].top()<t[2].v-t[1].v) ans+=t[2].v-q[t[2].id].top(),q[t[2].id].pop(),q[t[2].id].push(t[2].v-t[1].v);
			else q[t[1].id].push(t[1].v-t[0].v),ans+=t[1].v;
		}
	}
	printf("%d\n",ans);
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}
//I need calm down
//I am so silly and stupid