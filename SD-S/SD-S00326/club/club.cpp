#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N=1e5+10;
int n,T;
struct node{
	int v,id;
}a[N][4];
priority_queue<PIII> q[4];
int dt[N][3];

bool cmp(node a,node b){
	return a.v>b.v;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i][j].v);
			a[i][j].id=j;
		}
		sort(a[i]+1,a[i]+3+1,cmp);
		dt[i][1]=-a[i][1].v+a[i][2].v;
		dt[i][2]=-a[i][2].v+a[i][3].v;
	}
	
	for(int i=1;i<=n;i++){
		q[a[i][1].id].push({a[i][2].v-a[i][1].v,{i,1}});
		for(int j=1;j<=2;j++){
			for(int k=1;k<=3;k++){
				if(q[k].size()>n/2){
					auto t=q[k].top();
					q[k].pop();
					int id=t.second.first;
					int op=t.second.second;
					q[a[id][op+1].id].push({dt[id][op],{id,op+1}});
				}
			}
		}
	}
	
	int res=0;
	for(int i=1;i<=3;i++){
		while(q[i].size()){
			auto t=q[i].top();
			q[i].pop();
			int id=t.second.first,op=t.second.second;
			res+=a[id][op].v;
		}
	}
	printf("%d\n",res);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
