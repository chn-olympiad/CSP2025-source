#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005],b[100005],c[100005],p[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int x=0,y=0,z=0,ans=0,cnt=0,q=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i])	x++,ans+=a[i];
			else	if(b[i]>=a[i]&&b[i]>=c[i])	y++,ans+=b[i];
			else	z++,ans+=c[i];
		}
		if(x<=n/2&&y<=n/2&&z<=n/2){
			printf("%d\n",ans);
			continue;
		}
		if(x>n/2){
			q=x-n/2;
			for(int i=1;i<=n;i++)
				if(a[i]>=b[i]&&a[i]>=c[i])	p[++cnt]=min(a[i]-b[i],a[i]-c[i]);
		}
		else	if(y>n/2){
			q=y-n/2;
			for(int i=1;i<=n;i++)
				if(b[i]>=a[i]&&b[i]>=c[i]&&!(a[i]>=b[i]&&a[i]>=c[i]))	p[++cnt]=min(b[i]-a[i],b[i]-c[i]);
		}
		else{
			q=z-n/2;
			for(int i=1;i<=n;i++)
				if(!(a[i]>=b[i]&&a[i]>=c[i])&&!(b[i]>=a[i]&&b[i]>=c[i]))	p[++cnt]=min(c[i]-b[i],c[i]-a[i]);
		}
		sort(p+1,p+cnt+1);
		for(int i=1;i<=q;i++)	ans-=p[i];
		printf("%d\n",ans);
	}
	return 0;
}
