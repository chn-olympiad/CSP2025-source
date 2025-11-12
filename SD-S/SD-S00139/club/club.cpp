#include<bits/stdc++.h>
using namespace std;
int n,a[100001][3],sum;
struct node{
	int x,a;
	friend bool operator<(node x,node y){
		return x.a<y.a;
	}
};
priority_queue<node>q[3],e;
int F(int x,int o){
	int t;
	if(o==0)	t=max(a[x][1],a[x][2]);
	if(o==1)	t=max(a[x][0],a[x][2]);
	if(o==2)	t=max(a[x][0],a[x][1]);
	return t-a[x][o];
}
void f(int x,int o){
	int t,s;
	q[o].push({x,F(x,o)});
	sum+=a[x][o];
	if(q[o].size()<=n>>1)	return;
	node f=q[o].top();
	q[o].pop();
	if(o==0){
		if(a[f.x][1]>a[f.x][2])	s=1;
		else					s=2;
	}
	if(o==1){
		if(a[f.x][0]>a[f.x][2])	s=0;
		else					s=2;
	}
	if(o==2){
		if(a[f.x][0]>a[f.x][1])	s=0;
		else					s=1;
	}
	sum+=f.a;
	q[s].push({f.x,f.a});
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<3;i++){
			q[i]=e;
		}
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2])	f(i,0);
			else{
				if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2])	f(i,1);
				else										f(i,2);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
