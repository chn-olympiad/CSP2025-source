#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef long long ll;

inline ll readl(){
	ll x=0,y=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')y=-y;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	}
	return x*y;
}
void writel(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else writel(x/10),putchar(x%10+'0');
}
inline ll lmax(ll a,ll b){return (a>b?a:b);}
inline ll lmin(ll a,ll b){return (a<b?a:b);}
const ll N=1e5+10;
ll n;
struct Node{
	ll a,b,c,dis;
}a[N];
inline ll solve(){
	n=readl();ll Sum=0;
	vector<ll>A,B,C,iss,srt;
	for(ll i=1;i<=n;i++){
		a[i].a=readl();
		a[i].b=readl();
		a[i].c=readl();
		ll mx=lmax(lmax(a[i].a,a[i].b),a[i].c);
		ll mn=lmin(lmin(a[i].a,a[i].b),a[i].c);
		ll mid=a[i].a+a[i].b+a[i].c-mx-mn;
		a[i].dis=mx-mid;
		if(a[i].a==mx) A.push_back(i);
		else if(a[i].b==mx) B.push_back(i);
		else C.push_back(i);
		Sum+=mx;
	}
	ll An=A.size(),Bn=B.size(),Cn=C.size();
	ll val=n/2;
	if(An<=val&&Bn<=val&&Cn<=val) return Sum;
	if(An>val)iss=A;
	else if(Bn>val)iss=B;
	else iss=C;
	for(ll i:iss) srt.push_back(a[i].dis);
	sort(srt.begin(),srt.end());
	ll chosen=iss.size()-val;
	for(ll i=0;i<chosen;i++)
		Sum-=srt[i];
	return Sum;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T=readl();
	while(T--){
		writel(solve());
		puts("");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//AFO