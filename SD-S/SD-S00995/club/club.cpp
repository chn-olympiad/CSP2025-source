#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=2e5+5,INF=1e9;
struct node{
	int a[5],tx,ty;
}p[N];
bool cmp(node x,node y){
	return x.a[x.ty]-x.a[x.tx]>y.a[y.ty]-y.a[y.tx];
}
bool Ax,Bx,Cx;
int t,n,ans,s[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0,s[1]=0,s[2]=0,s[3]=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&p[i].a[1],&p[i].a[2],&p[i].a[3]);
			int a=p[i].a[1],b=p[i].a[2],c=p[i].a[3];
			if(a<=b&&b<=c){
				p[i].tx=3,p[i].ty=2;
			}else if(a<=c&&c<=b){
				p[i].tx=2,p[i].ty=3;
			}else if(b<=a&&a<=c){
				p[i].tx=3,p[i].ty=1;
			}else if(b<=c&&c<=a){
				p[i].tx=1,p[i].ty=3;
			}else if(c<=a&&a<=b){
				p[i].tx=2,p[i].ty=1;
			}else if(c<=b&&b<=a){
				p[i].tx=1,p[i].ty=2;
			}
		}
		for(int i=1;i<=n;i++){
			ans+=p[i].a[p[i].tx],s[p[i].tx]++;
		}
		for(int i=1;i<=3;i++){
			if(s[i]>n/2){
				sort(p+1,p+n+1,cmp);
				for(int j=1;j<=n&&s[i]>n/2;j++){
					if(p[j].tx==i){
						ans+=p[j].a[p[j].ty]-p[j].a[p[j].tx],s[i]--;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
