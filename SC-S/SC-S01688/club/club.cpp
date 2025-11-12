#include<bits/stdc++.h>
using namespace std;
const int N=100005,inf=0x3f3f3f3f;
int T,n,ans;
struct node{
	int b[4];
}a[N];
bool cmp(node x1,node x2){
	for(int i=1;i<=3;i++)if(x1.b[i]!=x2.b[i])return x1.b[i]<x2.b[i];
	return 0;
}
priority_queue<pair<int,int>>q[4];
int big(node xx){
	int mx=0;
	for(int i=1;i<=3;i++)mx=max(mx,xx.b[i]);
	for(int i=1;i<=3;i++)if(mx==xx.b[i])return i;
}
int sebig(node xx){
	int t1=big(xx),mn=inf,t2;
	for(int i=1;i<=3;i++)mn=min(mn,xx.b[i]);
	for(int i=1;i<=3;i++)if(mn==xx.b[i])t2=i;
	return 6-t1-t2;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].b[1],&a[i].b[2],&a[i].b[3]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int put=big(a[i]),sput=sebig(a[i]);
		q[put].push({a[i].b[sput]-a[i].b[put],i});
		ans+=a[i].b[put];
		if(q[put].size()>(n/2)){
			auto[x,ix]=q[put].top();
			q[put].pop();
			int sput=sebig(a[ix]);
			int ssput=6-put-sput;
			if(q[sput].size()<(n/2)){
				q[sput].push({a[ix].b[ssput]-a[ix].b[sput],ix});
				ans+=x;
			}else{
				q[ssput].push({0,ix});
				ans+=a[ix].b[ssput]-a[ix].b[put];
			}
		}
	}
	for(int i=1;i<=3;i++){
		while(!q[i].empty())q[i].pop();
	}
	printf("%d\n",ans);
	ans=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}