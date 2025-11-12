#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5,M = 1e6 + 5;
#define ll long long
ll n,m,k;
ll c,a[N];
struct Edge{
	ll u,v,w;
}e[M];
struct To{
	ll nm,sm;
	pair<ll,ll> g[N]; //first:v second:w
}ch[N];
ll fa[N];
ll cnt,ans;
bool cmp(Edge x,Edge y){
	return x.w < y.w;
}
ll findr(ll x){
	return fa[x] == x ? x : findr(fa[x]);
}
void Kruscal(){
	for(int i = 1;i <= n;i++){
		ll x = findr(e[i].u),y = findr(e[i].v);
		if(x == y) continue;
		fa[x] = y;
		cnt++;
		ans += e[i].w;
		/*
		ch[e[i].u].nm++;
		ch[e[i].u].g[ch[e[i].u].nm].first = e[i].v,ch[e[i].u].g[ch[e[i].u].nm].second = e[i].w;
		ch[e[i].u].sm += e[i].w;
		ch[e[i].v].nm++;
		ch[e[i].v].g[ch[e[i].v].nm].first = e[i].u,ch[e[i].v].g[ch[e[i].v].nm].second = e[i].w;
		ch[e[i].v].sm += e[i].w;
		*/
		if(cnt == n - 1) break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		/*
		ch[e[i].u].nm++;
		ch[e[i].u].g[ch[e[i].u].nm].first = e[i].v;
		ch[e[i].u].sm += e[i].w;
		ch[e[i].u].g[ch[e[i].u].nm].second = e[i].w;
		ch[e[i].v].nm++;
		ch[e[i].v].g[ch[e[i].v].nm].first = e[i].u;
		ch[e[i].v].sm += e[i].w;
		ch[e[i].v].g[ch[e[i].u].nm].second = e[i].w;
		*/
	}
	while(k--){
		cin>>c;
		for(int i = 1;i <= n;i++) cin>>a[i];
		/*
		ll mi = 0,p;
		bool flg = 0;
		for(int i = 1;i <= m;i++){
			//cout<<i<<" "<<ch[i].sm<<" "<<c + ch[i].nm * a[i]<<endl;
			if(ch[i].sm > a[i] * ch[i].nm + c){
				flg = 1;
				if(mi < ch[i].sm - ch[i].nm * a[i] - c){
					mi = ch[i].sm - ch[i].nm * a[i] - c;
					p = i;
				}
			}
		}
		cout<<mi<<" "<<p<<endl;
		if(!flg) continue;
		ch[p].sm = a[p] * ch[p].nm;
		ans += c;
		for(int i = 1;i <= ch[p].nm;i++){
			ch[p].g[i].second = a[p];
			for(int j = 1;j <= ch[ch[p].g[i].first].nm;j++){
				if(ch[ch[p].g[i].first].g[j].first == p){
					ch[ch[p].g[i].first].sm -= ch[ch[p].g[i].first].g[j].second - a[p];
					ch[ch[p].g[i].first].g[j].second = a[p];
					break;
				}
			}
		}
		for(int i = 1;i <= m;i++){
			if(e[i].u == p || e[i].v == p) e[i].w = a[p];
		}
		*/
	}
	sort(e+1,e+m+1,cmp);
	Kruscal();
	cout<<ans<<endl;
	return 0;
}