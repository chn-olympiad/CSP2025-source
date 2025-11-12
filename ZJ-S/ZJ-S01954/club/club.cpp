#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using std::cin;using std::cout;
constexpr int N=100005;
int t,n,c[4],ans;
struct A{int a[4],a1,a2;}a[N];
struct B{int id,d;inline bool operator<(const B &x)const{return d>x.d;}};
std::priority_queue<B>q[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	for(cin>>t;t--;cout<<ans<<'\n'){
		cin>>n;for(int i=1;i<=3;++i) for(;!q[i].empty();q[i].pop());ans=0;
		for(int i=1;i<=n;++i){
			cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3];c[1]=1;c[2]=2;c[3]=3;
			std::sort(c+1,c+4,[&](int u,int v){return a[i].a[u]>a[i].a[v];});
			a[i].a1=c[1];a[i].a2=c[2];
		}
		std::sort(a+1,a+n+1,[](A c,A d){return c.a[c.a1]>d.a[d.a1];});
		for(int i=1;i<=n;++i){
			int k1=a[i].a[a[i].a1]-a[i].a[a[i].a2];
			if(q[a[i].a1].size()<n/2){ans+=a[i].a[a[i].a1];q[a[i].a1].push(B{i,k1});}
			else{
				if(k1<q[a[i].a1].top().d){ans+=a[i].a[a[i].a2];q[a[i].a2].push(B{i,k1});}
				else{
					int k=q[a[i].a1].top().id,k3=a[k].a[a[k].a1]-a[k].a[a[k].a2];
					ans+=a[i].a[a[i].a1]-k3;
					q[a[i].a1].pop();q[a[i].a1].push(B{i,k1});q[a[k].a2].push(B{k,k3});
				}
			}
		}
	}
	return 0;
}
