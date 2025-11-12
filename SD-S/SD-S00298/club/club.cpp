#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct node{
	int s,pl,b;
}a[N<<2];
int t,n;
long long ans;
priority_queue<pair<int,int> > q[3];
int read(){
	char c=getchar();
	int re=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) re=(re<<1)+(re<<3)+c-'0';
	return re;
}
bool cmp(node x,node y){
	if(x.pl==y.pl){
		if(x.s==y.s) return x.b<y.b; 
		return x.s>y.s;
	}
	return x.pl<y.pl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[3*i-3+j].s=read();
				a[3*i-3+j].pl=i;
				a[3*i-3+j].b=j-1;
			}
		}
		sort(a+1,a+1+3*n,cmp);
		for(int i=0;i<3;i++){
			while(q[i].size()) q[i].pop();
		}
		for(int i=0;i<n;i++){
			int g=a[3*i+1].b;
			if(q[g].size()<n/2){
				ans+=a[3*i+1].s;
				q[g].push(make_pair(a[3*i+2].s-a[3*i+1].s,i));
			}
			else{
				int mina=q[g].top().first;
				if(mina<=a[3*i+2].s-a[3*i+1].s){
					ans+=a[3*i+2].s;
					q[a[3*i+2].b].push(make_pair(a[3*i+3].s-a[3*i+2].s,i));
				}
				else{
					int pre=q[g].top().second;
					q[a[3*pre+2].b].push(make_pair(a[3*pre+3].s-a[3*pre+2].s,pre));
					q[g].pop();
					ans+=mina;
					q[g].push(make_pair(a[3*i+2].s-a[3*i+1].s,i));
					ans+=a[3*i+1].s;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
