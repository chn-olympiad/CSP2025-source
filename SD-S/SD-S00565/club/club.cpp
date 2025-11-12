#include<bits/stdc++.h>
using namespace std;
struct xin{
	long long a1,a2,a3;
};
bool cmp1(xin x,xin y){
	return x.a1 >y.a1 ;
}bool cmp2(xin x,xin y){
	return x.a2 >y.a2 ;
}
long long t,n,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		xin s[n+1];
		bool f=true,F=true;
		for(long long i=1;i<=n;i++){
			scanf("%lld %lld %lld",&s[i].a1 ,&s[i].a2 ,&s[i].a3 );
			if(s[i].a2!=0) F=false;
			if(s[i].a3 !=0) f=false;
		}if(f==true){
			sort(s+1,s+n+1,cmp1);
			for(long long i=1;i<=n/2;i++)	ans+=s[i].a1;	
			if(F) printf("%lld",ans);
			else{
				long long ans2=0;
				for(long long i=n/2+1;i<=n;i++) ans+=s[i].a2;
				sort(s+1,s+n+1,cmp2);
				for(long long i=1;i<=n;i++){
					if(i<=n/2) ans2+=s[i].a2 ;
					else ans2+=s[i].a1 ;
				}printf("%lld",max(ans,ans2));
			}
		}else printf("%lld",0); 
		if(t!=0) cout<<endl;
	}
	return 0;
}
 
