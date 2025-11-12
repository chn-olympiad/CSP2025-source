//code by JuRuoOIer(Luogu 476093)
//problem:road
//time used:80min
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<deque>
#include<random>
#define ll long long
#define ull unsigned long long
#define lf double
#define ld long double
using namespace std;
void file(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
struct node{
	ll u,v,w;
};
bool operator <(node x,node y){
	return x.w<y.w;
}
ll n,m,k,u,v,w,fa[200010],a[20][200010],c[20];
//now:matching vertex of the locked vertexes. 
//vis:lock/unlock 
node q[2000000];
inline ll fnd(ll x){
	if(fa[x]!=x)fa[x]=fnd(fa[x]);
	return fa[x];
}
inline void merg(ll x,ll y){
	fa[x]=fa[y];
}
int main(){
	ld st=clock();
	file();
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		q[i].u=u;
		q[i].v=v;
		q[i].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			q[m].u=i+n;
			q[m].v=j;
			q[m].w=a[i][j];
			m++;
		}
	} 
	sort(q,q+m);
	ll ans=999999999999999999ll;
	for(int i=0;i<(1ll<<k);i++){
		ll sum=0,cnt=n;
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				sum+=c[j+1];
				cnt++;
			}
		}
		cnt--;
//		cout<<i<<endl;
		for(int j=0;cnt>0;j++){
			if(q[j].u>n&&(!((i>>q[j].u-n-1)&1))){
				continue;
			}
//			cout<<"    "<<j<<' '<<cnt<<' '<<q[j].u<<' '<<fnd(q[j].u)<<' '<<q[j].v<<' '<<fnd(q[j].v)<<' '<<q[j].w<<endl;
			if(fnd(q[j].u)!=fnd(q[j].v)){
				sum+=q[j].w;
				cnt--;
				merg(q[j].u,q[j].v);
			}
		}
//		cout<<"    "<<sum<<endl;
//		cout<<i<<' '<<sum<<endl;
		ans=min(ans,sum);
		ld ed=clock();
		if((ed-st)/CLOCKS_PER_SEC>0.9){
			break;
		}
	}
	cout<<ans;
	return 0;
}
/*
我们所可以自慰的，想来想去，也只是对于将来的希望。
希望是附丽于存在的，有存在，便有希望，有希望，便是光明。
……
雪地车在成千上万个地标间穿梭，可能的救援范围浩如烟海，集合所有队伍的方案却寥若晨星。
但你没时间绝望，你甚至没时间算出那个数字。
你只能算出答案对 $998244353$ 取模的结果。
那便是希望。
即便需要取模，也是光明。 
*/
