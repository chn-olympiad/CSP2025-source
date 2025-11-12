#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath> 
#include<queue>
#include<algorithm>
#include<bitset>
#define ll long long
//battles have little meaning,save for the prize to be won
//在我们面前，卖弄计谋亦是无用 
using namespace std;
const int N=1e5+7;
struct node{
	ll a,b,c,fir,fi,se;
}m[N];
bool comp(node x,node y){
	return x.fir-x.se>y.fir-y.se;
}
ll n,t,num[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(ll u=1;u<=t;u++){
	    memset(num,0,sizeof num);
		ll ans=0;
		scanf("%lld",&n);
	    for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&m[i].a,&m[i].b,&m[i].c);
			m[i].fir=max(m[i].a,max(m[i].b,m[i].c));
			if(m[i].fir==m[i].a){
				m[i].fi=1;m[i].se=max(m[i].b,m[i].c);
			}
	    	else if(m[i].fir==m[i].b){
	    		m[i].fi=2;m[i].se=max(m[i].a,m[i].c);
			}
	    	else{
	    		m[i].fi=3;m[i].se=max(m[i].a,m[i].b);
			}
		}
	    sort(m+1,m+n+1,comp);
	    for(ll i=1;i<=n/2;i++){
	    	ans+=m[i].fir;
	    	num[m[i].fi]++;
		}
		for(ll i=n/2+1;i<=n;i++){
			if(num[m[i].fi]==n/2){
				ans+=m[i].se;
			}
			else{
				ans+=m[i].fir;num[m[i].fi]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}