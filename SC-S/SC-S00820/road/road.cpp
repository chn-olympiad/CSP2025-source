#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define MAXN 10010
int b[MAXN],one,two,three;
struct data{
	int u1,u2,w3;
};
bool bit(){
	int a,b;
	return a < b;
}
data a[MAXN];
signed main(){
	int n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i].u1,&a[i].u2,&a[i].w3);
	for(int i=1;i<=k;i++)  for(int j=1;j<=n+1;j++) scanf("%lld",&b[i]);
	int ans=b[1],Max=0,set,set1;
	for(int i=1;i<=k*(n+1)-2;i++){
		if(b[i]+b[i+1]+b[i+2]>=Max){
			Max=b[i]+b[i+1]+b[i+2];
			one=b[i],two=b[i+1],three=b[i+2];
			set=max(a[i].u1,a[i].u2),set=max(set,a[i].w3);
			set1=max(a[i+2].u1,a[i+2].u2),set=max(set1,a[i+2].w3);
		}
	}
	int fox=0;
	for(int i=1;i<=n+1;i++) fox+=b[i];
	fox=fox+set1+set;
	printf("%lld",fox);
	return 0;
}