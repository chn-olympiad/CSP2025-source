#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define endl "\n"
#define ft first
#define sd second
using namespace std;
const ll N=1e6+5,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
ll n,m,T;
struct lx{
	ll a,id;
	bool operator<(const lx &s)const{
		return a<s.a;
	}
};
struct dat{
	lx a[5];
}sr[N];
struct dlx{
	ll cz,i,j;
	bool operator<(const dlx &s)const{
		return cz>s.cz;
	}
};
priority_queue<dlx> q[5];
ll a[N][5],g[N][5];
ll gs[5],ans=0;
void sovle(){
	cin>>n;
	for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
	for(int i=1;i<=3;i++)gs[i]=0;
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)cin>>sr[i].a[j].a,sr[i].a[j].id=j;
		sort(sr[i].a+1,sr[i].a+1+3);
//		for(int j=1;j<=3;j++)cout<<sr[i].a[j].a<<' '<<sr[i].a[j].id<<endl;
		for(int j=1;j<=3;j++)a[i][j]=sr[i].a[j].a,g[i][j]=sr[i].a[j].id;
		q[g[i][3]].push({a[i][3]-a[i][2],i,3});
		ans+=a[i][3];gs[g[i][3]]++;
	}
//	ll suu=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++)cout<<g[i][j]<<' ';cout<<endl;
//		for(int j=1;j<=3;j++)cout<<a[i][j]<<' ';cout<<endl;
//		cout<<endl;
//	}cout<<endl;
//	cout<<ans<<"!\n";
	while(1){
//		suu++;
		ll boo=0;
//		for(int i=1;i<=3;i++)cout<<gs[i]<<" ";cout<<endl;
		for(int i=1;i<=3;i++)if(gs[i]>n/2){boo=1;break;}
		if(!boo)break;
		for(int t=1;t<=3;t++)if(gs[t]>n/2){
			if(!q[t].empty()){
				dlx x=q[t].top();q[t].pop();
				ans-=x.cz;
				if(x.j==2){continue;}
				q[g[x.i][x.j-1]].push({a[x.i][x.j-1]-a[x.i][x.j-2],x.i,x.j-1});
				gs[g[x.i][x.j]]--;gs[g[x.i][x.j-1]]++;
			}
			break;
		}
	}
	cout<<ans<<endl;
	
}
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		sovle();
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/
