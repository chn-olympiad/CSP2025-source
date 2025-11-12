#include<bits/stdc++.h>
using namespace std;
int T,n;
long long ans;
int a[100002][3];
void solve(){
	scanf("%d",&n);
	ans=0ll;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	priority_queue<pair<int,int> > qa,qb,qc;
	for(int i=1;i<=n;i++){
		if(a[i][0]>a[i][1]){
			if(a[i][0]>a[i][2])	qa.push({a[i][0],i});
			else	qc.push({a[i][2],i});
		}
		else{
			if(a[i][1]>a[i][2])
				qb.push({a[i][1],i});
			else
				qc.push({a[i][2],i});
		}
	}
	if(qa.size()>(n>>1)){
		int cnt=qa.size()-(n>>1);
		priority_queue<int,vector<int>,greater<int> > que;
		queue<pair<int,int> > q;
		int si=qa.size();
		for(int i=1;i<=si;i++){
			que.push(a[qa.top().second][0]-max(a[qa.top().second][1],a[qa.top().second][2]));
//			qa.push(qa.top());
			q.push(qa.top());
			qa.pop();
		}
		while(q.size()){
			qa.push(q.front());
			q.pop();
		}
		for(int i=1;i<=cnt;i++){
			ans-=que.top();
			que.pop();
		}
	}
	if(qb.size()>(n>>1)){
		int cnt=qb.size()-(n>>1);
		priority_queue<int,vector<int>,greater<int> > que;
		queue<pair<int,int> > q;
//		printf("%d\n",qb.size());
		int si=qb.size();
		for(int i=1;i<=si;i++){
//			printf("%d ",a[qb.top().second][1]);
			que.push(a[qb.top().second][1]-max(a[qb.top().second][0],a[qb.top().second][2]));
//			qb.push(qb.top());
			q.push(qb.top());
			qb.pop();
		}
		while(q.size()){
			qb.push(q.front());
			q.pop();
		}
		for(int i=1;i<=cnt;i++){
			ans-=que.top();
//			printf("%d ",ans);
			que.pop();
		}
//		printf("\n");
	}
	if(qc.size()>(n>>1)){
		int cnt=qc.size()-(n>>1);
		priority_queue<int,vector<int>,greater<int> > que;
		queue<pair<int,int> > q;
		int si=qc.size();
		for(int i=1;i<=si;i++){
			que.push(a[qc.top().second][2]-max(a[qc.top().second][1],a[qc.top().second][0]));
			q.push(qc.top());
			qc.pop();
		}
		while(q.size()){
			qc.push(q.front());
			q.pop();
		}
		for(int i=1;i<=cnt;i++){
			ans-=que.top();
			que.pop();
		}		
	}
//	printf("%lld\n",ans);
	while(qa.size()){
		ans+=qa.top().first;
		qa.pop();
	}
	while(qb.size()){
		ans+=qb.top().first;
		qb.pop();
	}
	while(qc.size()){
		ans+=qc.top().first;
		qc.pop();
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}

