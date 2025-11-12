#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
struct node{
	ll a,b,c;
}a[N];
ll t,n;
bool cnt4(node a,node b){
	return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));
}
bool cnt1(node a,node b){
	return a.a-max(a.b,a.c)>b.a-max(b.b,b.c);
}
bool cnt2(node a,node b){
	return a.b-max(a.a,a.c)>b.b-max(b.a,b.c);
}
bool cnt3(node a,node b){
	return a.c-max(a.a,a.b)>b.c-max(b.a,b.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ll ans1=0,ans2=0,ans3=0,ans4=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
		sort(a+1,a+1+n,cnt1);
		for(ll i=1;i<=n/2;i++)ans1+=a[i].a;
		for(ll i=n/2+1;i<=n;i++)ans1+=max(a[i].b,a[i].c);
		
		sort(a+1,a+1+n,cnt2);
		for(ll i=1;i<=n/2;i++)ans2+=a[i].b;
		for(ll i=n/2+1;i<=n;i++)ans2+=max(a[i].a,a[i].c);
		
		sort(a+1,a+1+n,cnt3);
		for(ll i=1;i<=n/2;i++)ans3+=a[i].c;
		for(ll i=n/2+1;i<=n;i++)ans3+=max(a[i].a,a[i].b);
		
		sort(a+1,a+1+n,cnt4);
		ll x=0,y=0,z=0;
		for(ll i=1;i<=n;i++){
			if(x<n/2&&(a[i].a>=a[i].b||y==n/2)&&(a[i].a>=a[i].c||z==n/2))x++,ans4+=a[i].a;
			else if(y<n/2&&(a[i].b>=a[i].a||x==n/2)&&(a[i].b>=a[i].c||z==n/2))y++,ans4+=a[i].b;
			else if(z<n/2&&(a[i].c>=a[i].a||x==n/2)&&(a[i].c>=a[i].b||y==n/2))z++,ans4+=a[i].c;
		}
		printf("%lld\n",max(max(ans1,ans4),max(ans2,ans3)));
	}
	return 0;
}
