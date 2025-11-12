#include<bits/stdc++.h>
using namespace std;
int t,n,d[3],k,ans;
struct node{
	int s,wh,ma;
}a[300005];
bool cmp(node a,node b){
	return a.s>b.s;
}
priority_queue<int> q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		k=0;ans=0;
		scanf("%d",&n);
		int p1=q[0].size(),p2=q[1].size(),p3=q[2].size();
		for(int i=1;i<=n;i++){
			if(p1>0){
				q[0].pop();
				p1--;
			}
			if(p2>0){
				q[1].pop();
				p2--;
			}
			if(p3>0){
				q[2].pop();
				p3--;
			}
			scanf("%d%d%d",&d[0],&d[1],&d[2]);
			if(d[0]>=d[2]&&d[1]>=d[2]){
				if(d[0]>=d[1]){
					a[++k]={d[0],0,d[1]};
				}
				else{
					a[++k]={d[1],1,d[0]};
				}
			}
			else if(d[0]>=d[1]&&d[2]>=d[1]){
				if(d[0]>=d[2]){
					a[++k]={d[0],0,d[2]};
				}
				else{
					a[++k]={d[2],2,d[0]};
				}
			}
			else{
				if(d[1]>=d[2]){
					a[++k]={d[1],1,d[2]};
				}
				else{
					a[++k]={d[2],2,d[1]};
				}
			}
		}
		sort(a+1,a+1+k,cmp);
		for(int i=1;i<=k;i++){
			if(q[a[i].wh].size()+1<=n/2){
				q[a[i].wh].push(-a[i].s+a[i].ma);
				ans+=a[i].s;
			}
			else{
				if(a[i].s+q[a[i].wh].top()>a[i].ma){
					ans+=a[i].s+q[a[i].wh].top();
					q[a[i].wh].pop();
					q[a[i].wh].push(-a[i].s+a[i].ma);
				}
				else{
					ans+=a[i].ma;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
