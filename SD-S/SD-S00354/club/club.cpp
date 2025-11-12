#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#define ll long long
#define fir first
#define sec second
#define pb push_back
#define MaxN 100005 
using namespace std;
struct P{
	ll a[4],pos;
}a[MaxN],b[MaxN];
ll T,n,ans,tmp;
bool cmpa(P a,P b){return a.a[1]>=b.a[1];}
bool cmpb(P a,P b){return a.a[2]>=b.a[2];}
bool cmpc(P a,P b){return a.a[3]>=b.a[3];}
ll cnt(ll pos){return b[pos].a[1]+b[pos].a[2]+b[pos].a[3]-max(b[pos].a[1],max(b[pos].a[2],b[pos].a[3]));}
void P1(){
	set<ll>unq;
	map<ll,bool>apA,apB;
	ans=tmp=0;
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3],a[i].pos=i;
	for(ll i=1;i<=n;i++)for(ll j=1;j<=3;j++)b[i].a[j]=a[i].a[j],b[i].pos=i;

	sort(a+1,a+n+1,cmpa);
	for(ll i=1;i<=n/2;i++)if(a[i].a[1]!=0)apA[a[i].pos]=1,ans+=a[i].a[1];

	sort(a+1,a+n+1,cmpb);
	for(ll i=1;i<=n/2;i++){
		if(a[i].a[2]!=0){
			apB[a[i].pos]=1;
			ans+=a[i].a[2];
			if(apA[a[i].pos])unq.insert(a[i].pos);
		}
	}

	sort(a+1,a+n+1,cmpc);
	for(ll i=1;i<=n/2;i++){
		ans+=a[i].a[3];
		if(apA[a[i].pos]||apB[a[i].pos])unq.insert(a[i].pos);
	}
	for(set<ll>::iterator it=unq.begin();it!=unq.end();it++)ans-=cnt((*it));
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)P1();
	return 0;
}

