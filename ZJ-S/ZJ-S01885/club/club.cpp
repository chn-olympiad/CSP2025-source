#include<bits/stdc++.h>
using namespace std;
long long n,ma,i,k,ans,x,y,z,t;
long long a[100001],b[100001],c[100001],s[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ans=0,x=0,y=0,z=0,k=0,ma=0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			ma=max(a[i],b[i]),ma=max(ma,c[i]);
			ans+=ma;
			if(a[i]==ma) x++;
			else if(b[i]==ma) y++;
			else z++;
		}
		if(x>n/2){
			for(i=1;i<=n;i++){
				ma=max(a[i],b[i]),ma=max(ma,c[i]);
				if(a[i]==ma)  s[++k]=a[i]-max(b[i],c[i]);
			}
			sort(s+1,s+1+k);
			for(i=1;i<=x-n/2;i++) ans-=s[i];
		}
		else if(y>n/2){
			for(i=1;i<=n;i++){
				ma=max(a[i],b[i]),ma=max(ma,c[i]);
				if(b[i]==ma)  s[++k]=b[i]-max(a[i],c[i]);
			}
			sort(s+1,s+1+k);
			for(i=1;i<=y-n/2;i++) ans-=s[i];
		}
		else if(z>n/2){
			for(i=1;i<=n;i++){
				ma=max(a[i],b[i]),ma=max(ma,c[i]);
				if(c[i]==ma)  s[++k]=c[i]-max(b[i],a[i]);
			}
			sort(s+1,s+1+k);
			for(i=1;i<=z-n/2;i++) ans-=s[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}