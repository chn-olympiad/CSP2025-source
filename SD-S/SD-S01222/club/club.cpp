#include<bits/stdc++.h> 
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
struct node{
	int x,y,z;
	int del1,del2;
	bool operator<(const node&q)const{
		return del1>q.del1;
	}
	bool operator>(const node&q)const{
		return del2>q.del2;
	}
}a[100010];
LL f[100010][5];
bool cmp1(node p,node q){
	int s=max(p.x,p.y),t=s=max(q.x,q.y);
	return s>t;
}
bool cmp2(node p,node q){
	return p.del1<q.del1;
}
priority_queue<node,vector<node> >pq1,pq2,q1,q2;
priority_queue<node,vector<node>,greater<node> > pq_1,pq_2,pq_3;
LL ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	pii d,e,g;
	scanf("%d",&t);
	while(t--){
		while(!pq1.empty())pq1.pop();
		while(!pq2.empty())pq2.pop();
		while(!pq_1.empty())pq_1.pop();
		while(!pq_2.empty())pq_2.pop();
		while(!pq_3.empty())pq_3.pop();
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].del1=a[i].x-a[i].y,a[i].del2=a[i].y-a[i].z;
//			a[i].x.se=1,a[i].y.se=2,a[i].z.se=3;
		}
		sort(a+1,a+n+1,cmp2);
//		for(int i=1,p1,p2;i<=n;i++){
//			p1=pq1.size(),p2=pq2.size();
//			if(p1==n/2){
//				pq1.push(a[i]);
//				node u=pq1.top();
//				pq2.push(u);
//				pq1.pop();
//			}else if(p2==n/2){
//		while(!pq2.empty()){
//			node u=pq2.top();
//			pq_2.push(pq2.top());
//			pq2.pop();
////			printf("2 %d %d %d %d %d\n",u.x,u.y,u.z,u.del1,0);
//		}
////		return 0;
//				pq2.push(a[i]);
//				node u=pq2.top();
//				pq1.push(u);
//				pq2.pop();
//			}else{
//				node u=a[i];
//				if(del1>0)pq1.push(u);
//				else pq2.push(u);
//			printf("3 %d %d %d\n",u.x,u.y,u.z);
//			}
////			printf("%d %d %d\n",u.x,u.y,u.z);
//		}
		for(int i=1;i<=n/2;i++)pq2.push(a[i]);
		for(int i=n/2+1;i<=n;i++)pq1.push(a[i]);
		q1=pq1,q2=pq2;
		while(!pq1.empty()){
			node u=pq1.top();
			u.del2+=u.del1;
			pq_1.push(u);
			pq1.pop();
//			printf("1 %d %d %d\n",u.x,u.y,u.z);
		}
		while(!pq2.empty()){
			pq_2.push(pq2.top());
			pq2.pop();
//			printf("2 %d %d %d\n",u.x,u.y,u.z);
		}
		if(pq_1.top().del1<0||pq2.top().del2<0){
			for(int i=1;pq_3.size()<n/2;i++){
				node u1=pq_1.top(),u2=pq_2.top();
	//			printf("1 %d %d %d 2 %d %d %d\n",u1.x,u1.y,u1.z,u2.x,u2.y,u2.z);
				if(u1.del2>=0&&u2.del2>=0)break;
				if(u1.del2<u2.del2)pq_3.push(u1),pq_1.pop();
				else pq_3.push(u2),pq_2.pop();
			}
		}
		while(!pq_1.empty())ans+=pq_1.top().x,pq_1.pop();
		while(!pq_2.empty())ans+=pq_2.top().y,pq_2.pop();
		while(!pq_3.empty())ans+=pq_3.top().z,pq_3.pop();
		printf("%lld\n",ans);
	}
	
	return 0;
}
