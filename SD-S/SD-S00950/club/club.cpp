#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+(c-'0'),c=getchar();
	return x;
}
struct node{
	int a,b,c;
	int x,kx,y,ky;
	bool operator <(const node &b) const{
		return x-y>b.x-b.y;
	}
}a[100005];
struct pai{
	int x,y;
};
bool cmp(pai a,pai b){
	return a.x>b.x;
}
int t,n;
priority_queue<node> q[3]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++){
			pai p[4]={{0,0},{read(),0},{read(),1},{read(),2}};
			a[i]={p[1].x,p[2].x,p[3].x,0,0,0,0};
			sort(p+1,p+1+3,cmp);
			a[i]={a[i].a,a[i].b,a[i].c,p[1].x,p[1].y,p[2].x,p[2].y};
		}
		int cnt[3]={0};
		for(int i=1;i<=n;i++){
			int kx=a[i].kx,ky=a[i].ky;
			if(cnt[kx]<n/2) cnt[kx]++,q[kx].push(a[i]);
			else{
				node x=q[kx].top();q[kx].pop();
				if(a[i].x+x.y-x.x>a[i].y) q[kx].push(a[i]),q[x.ky].push(x),cnt[x.ky]++;
				else q[ky].push(a[i]),q[kx].push(x),cnt[ky]++;
			}
		}
		int sum=0;
		while(!q[0].empty()) sum+=q[0].top().a,q[0].pop();
		while(!q[1].empty()) sum+=q[1].top().b,q[1].pop();
		while(!q[2].empty()) sum+=q[2].top().c,q[2].pop();
		printf("%d\n",sum);
	}
	return 0;
}
