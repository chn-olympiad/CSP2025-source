#include<bits/stdc++.h>
using namespace std;
#define int long long
struct aaa{
	int fr,to,a;
}a[2000005];
bool cmp(aaa x,aaa y){
	return x.a<y.a;
}
int n,m,k,f[20005],ans,l[20005],s[20005],nh;
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+2*k;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].fr,&a[i].to,&a[i].a);
	}
	for(int i=1;i<=k;i++){
		a[++m].fr=n+k+i,a[m].to=n+i;
		scanf("%lld",&a[m].a);
		for(int j=1;j<=n;j++){
			a[++m].fr=n+i,a[m].to=j;
			scanf("%lld",&a[m].a);
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int t1=find(a[i].fr),t2=find(a[i].to);
		if(t1==t2) continue;
		ans+=a[i].a;
		f[t1]=t2;
	}
	printf("%lld",ans);
	return 0;
}