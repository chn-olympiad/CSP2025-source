#include<bits/stdc++.h>
#define LL long long
#define run(now) cout<<"there"<<now<<endl;
#define N 200010
using namespace std;
inline LL read(){
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*f;
}
LL n;
struct node{
	LL x,i;
	bool operator<(const node a)const{
		return x>a.x;
	}
}a[N][4];
void solve(){
	n=read();
	priority_queue<int,vector<int>,greater<int> >q[4];
	LL ans=0;
	for(LL i=1;i<=n;i++){
		a[i][1].x=read();a[i][2].x=read();a[i][3].x=read();
		a[i][1].i=1;a[i][2].i=2;a[i][3].i=3;
		sort(a[i]+1,a[i]+4);
		if(q[a[i][1].i].size()==n/2){
			int now=q[a[i][1].i].top();
			if(now>a[i][1].x-a[i][2].x)ans+=a[i][2].x;
			else ans+=a[i][1].x-now,q[a[i][1].i].pop(),q[a[i][1].i].push(a[i][1].x-a[i][2].x);
		}
		else ans+=a[i][1].x,q[a[i][1].i].push(a[i][1].x-a[i][2].x);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		solve();
	}
	return 0;
}
