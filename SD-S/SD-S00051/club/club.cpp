#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<random>
#include<ctime> 
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<cstdlib>
#include<string>
#define ll long long
#define uint unsigned int
#define FOR(i,m,n) for(ll i=m;i<=n;i++)
#define FRO(i,m,n) for(ll i=m;i>=n;i--)
#define mp(a,b) make_pair(a,b) 
using namespace std;
inline ll read(){
	ll res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch&15),ch=getchar();
	return res*f;
}
const ll N=200005;
struct node{
	ll x,y,z,p;
}a[N];
bool cmp(node x,node y){
	return x.p>y.p;
}
ll cnt[4];
ll k[N][4];
void solve(){
	ll n=read();
	FOR(i,1,n){
		a[i].x=read();
		a[i].y=read();
		a[i].z=read();
		a[i].p=max(a[i].x,max(a[i].y,a[i].z));	
	}
	sort(a+1,a+1+n,cmp); 
	cnt[1]=cnt[2]=cnt[3]=0;
	ll sum=0;
	FOR(i,1,n){
		if(a[i].p==a[i].x)cnt[1]++,k[cnt[1]][1]=i,sum+=a[i].x;
		else if(a[i].p==a[i].y)cnt[2]++,k[cnt[2]][2]=i,sum+=a[i].y;
		else cnt[3]++,k[cnt[3]][3]=i,sum+=a[i].z;
	}
	priority_queue<ll>q;
	if(cnt[1]>n/2){
		FOR(i,1,cnt[1]){
			ll idx=k[i][1];
			ll x=max(a[idx].y,a[idx].z);
			q.push(x-a[idx].x);
		}
		while(cnt[1]>n/2)sum+=q.top(),q.pop(),cnt[1]--; 
	}
	if(cnt[2]>n/2){
		FOR(i,1,cnt[2]){
			ll idx=k[i][2];
			ll x=max(a[idx].x,a[idx].z);
			q.push(x-a[idx].y);
		}
		while(cnt[2]>n/2)sum+=q.top(),q.pop(),cnt[2]--; 
	}
	if(cnt[3]>n/2){
		FOR(i,1,cnt[3]){
			ll idx=k[i][3];
			ll x=max(a[idx].x,a[idx].y);
			q.push(x-a[idx].z);
		}
		while(cnt[3]>n/2)sum+=q.top(),q.pop(),cnt[3]--; 
	}
	printf("%lld\n",sum);
}
int main(){
//	freopen("club5.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T=read();
	while(T--)solve();
	return 0;
} 


/*
Wake up!
What should I do now?
Could I see the blossom? 
But now I may find you.

Why T1 so hard!!!!!!!!

45min.
*/






