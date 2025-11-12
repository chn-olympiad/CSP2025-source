#include<bits/stdc++.h>//ok
using namespace std;
const int N=1e5+50;
struct node{int x,id;}a[N][4];
priority_queue<pair<int,int> >q[4][4];
int cnt[4],ans,n,ni; 
void work(int k){
	int a,b,ai=0,bi=0,ax=0,bx=0;
	if(k==1) a=2,b=3;
	if(k==2) a=1,b=3;
	if(k==3) a=1,b=2;
	if(cnt[a]>cnt[b]) swap(a,b),swap(ai,bi);
	if(!q[k][a].empty()){
		ai=q[k][a].top().first,
		ax=q[k][a].top().second;	
	}
	if(!q[k][b].empty()){
		bi=q[k][b].top().first,
		bx=q[k][b].top().second;	
	}
	if(cnt[b]>=ni){
		ans+=ai;cnt[a]++;cnt[k]--;
		q[k][a].pop();
		return ;
	}
	if(!ai||!bi){
		if(!ai){
			ans+=bi;cnt[b]++;cnt[k]--;
			q[k][b].pop();
			return ;
		}
		else{
			ans+=ai;cnt[a]++;cnt[k]--;
			q[k][a].pop();
			return ;
		}
	} 
	if(ai>bi){
		ans+=ai;cnt[a]++;cnt[k]--;
		q[k][a].pop();
		return ;
	}
	else{
		ans+=bi;cnt[b]++;cnt[k]--;
		q[k][b].pop();
		return ;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;scanf("%d",&T);
	while(T--){
		for(int i=1;i<=3;i++)
		 for(int j=1;j<=3;j++)
		  while(!q[i][j].empty())q[i][j].pop();
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		scanf("%d",&n);ni=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1].x,&a[i][2].x,&a[i][3].x);
			a[i][1].id=1;a[i][2].id=2;a[i][3].id=3;
			if(a[i][1].x<a[i][2].x) swap(a[i][1],a[i][2]);
			if(a[i][2].x<a[i][3].x) swap(a[i][2],a[i][3]);
			if(a[i][1].x<a[i][2].x) swap(a[i][1],a[i][2]);
			cnt[a[i][1].id]++;
			ans+=a[i][1].x;
		//	p[i]=a[i][1].id;
			q[a[i][1].id][a[i][2].id].push({a[i][2].x-a[i][1].x,i});
		//	vis[i][0]=a[i][3].id;
		//	vis[i][1]=a[i][3].x-a[i][2].id;
			if(cnt[a[i][1].id]>ni)work(a[i][1].id); 
		//	printf("now%d\n",i);
		}
		printf("%d\n",ans);
	}
}