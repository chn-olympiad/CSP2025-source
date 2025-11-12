#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e5+50;
struct man{
	ll a1,a2,a3;
	bool f;
}m[maxn];
ll t,n,max1=INT_MIN,max2=INT_MIN,max3=INT_MIN,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(ll k=1;k<=t;++k){
		scanf("%lld",&n);
		for(ll i=1;i<=n;++i){
			scanf("%lld%lld%lld",&m[i].a1,&m[i].a2,&m[i].a3);
		}
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=n;++i)
			{
				if(m[j].f){
					continue;
				}
				else{
					if(m[j].a1>max1) max1=j;
					if(m[j].a2>max2) max2=j;
					if(m[j].a2>max2) max3=j;
				}	
			}
			sum+=m[max1].a1;
			m[max1].f=1;
			sum+=m[max2].a2;
			m[max2].f=1;
			sum+=m[max3].a3;
			m[max3].f=1;
			max1=0;
			max2=0;
			max3=0;
		}
		printf("%lld\n",&sum);
		sum=0;
		for(int i=1;i<=n;++i){
			m[i].f=0; 
		}
	}
	return 0;
} 