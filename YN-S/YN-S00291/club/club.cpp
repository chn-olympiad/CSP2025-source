#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,t,hee;
ll a[100001],b[100001],c[100001];
bool cmp(ll a,ll b){
	return a>b;
}
struct node{
	ll x,y,xy;
}s[100001];
bool cmp1(node a,node b){
	return a.xy>b.xy;
}
void so(ll x,ll he){
	if(x==n+1){
		hee=max(hee,he);
	}
	so(x+1,he+a[x]);
	so(x+1,he+b[x]);
	so(x+1,he+c[x]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ll y1=0,y2=0,ans=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
			if(b[i]!=0)y1=1;
			if(c[i]!=0)y2=1;
		}
		if(y1==0&&y2==0){
			sort(a+1,a+1+n,cmp);
			for(ll i=1;i<=n/2;i++){
				ans+=a[i];
			}
		}else if(y1!=0&&y2==0){
			for(ll i=1;i<=n;i++){
				s[i].x=a[i];
				s[i].y=b[i];
				s[i].xy=max(a[i],b[i]);
			}
			ll t1=1,t2=1;
			sort(s+1,s+1+n,cmp1);
			for(ll j=1;j<=n;j++){
				if(s[j].xy==s[j].x){
					t1++;
				}else{
					t2++;
				}
				if(t1>=n/2){
					ans+=s[j].y;
				}else if(t2>=n/2){
					ans+=s[j].x;
				}else{
					ans+=s[j].xy;
				}
			}
		}else{
			so(1,0);
			ans=hee;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
