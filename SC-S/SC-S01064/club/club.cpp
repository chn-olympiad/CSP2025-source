#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define ptc putchar
using namespace std;
const int N=1e5+9;
int t;
int n;
int a[N],b[N],c[N];
ll ans;
int cnta,cntb,cntc;
int p[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t){
		--t;
		scanf("%d",&n);
		ans=0;
		cnta=0;
		cntb=0;
		cntc=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",a+i,b+i,c+i);
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ans+=a[i];
				++cnta;
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				ans+=b[i];
				++cntb;
			}
			else{
				ans+=c[i];
				++cntc;
			}
		}
		if(cnta*2<=n&&cntb*2<=n&&cntc*2<=n){
			printf("%lld\n",ans);
			continue;
		}
		if(cnta*2>n){
			for(int i=1;i<=n;i++){
				p[i]=a[i]-max(b[i],c[i]);
				if(p[i]<0) p[i]=1e9;
			}
			sort(p+1,p+n+1);
			for(int i=1;i<=cnta-n/2;i++){
				ans-=p[i];
			}
			printf("%lld\n",ans);
		}
		else if(cntb*2>n){
			for(int i=1;i<=n;i++){
				p[i]=b[i]-max(a[i],c[i]);
				if(p[i]<0) p[i]=1e9;
			}
			sort(p+1,p+n+1);
			for(int i=1;i<=cntb-n/2;i++){
				ans-=p[i];
			}
			printf("%lld\n",ans);
		}
		else{
			for(int i=1;i<=n;i++){
				p[i]=c[i]-max(a[i],b[i]);
				if(p[i]<0) p[i]=1e9;
			}
			sort(p+1,p+n+1);
			for(int i=1;i<=cntc-n/2;i++){
				ans-=p[i];
			}
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}