#include<bits/stdc++.h>
using namespace std;
long long n,t,m,s1,s2,s3,ans,ss[100010],v;
struct Node{
	long long a,b,c;
}s[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=s1=s2=v=s3=0;
		scanf("%lld",&n);
		m=n/2;
		for(long long i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
				s1+=1;
				ans+=s[i].a;
			}
			else if(s[i].b>=s[i].c){
				s2+=1;
				ans+=s[i].b;
			}
			else{
				s3+=1;
				ans+=s[i].c;
			}
		}
		if(s1>m){
			for(long long i=1;i<=n;i++){
				if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
					v+=1;
					ss[v]=min(s[i].a-s[i].b,s[i].a-s[i].c);
				}
			}
			sort(ss+1,ss+v+1);
			for(long long i=1;i<=s1-m;i++){
				ans-=ss[i];
			}
		}
		else if(s2>m){
			for(long long i=1;i<=n;i++){
				if(s[i].b>=s[i].a&&s[i].b>=s[i].c){
					v+=1;
					ss[v]=min(s[i].b-s[i].a,s[i].b-s[i].c);
				}
			}
			sort(ss+1,ss+v+1);
			for(long long i=1;i<=s2-m;i++){
				ans-=ss[i];
			}
		}
		else if(s3>m){
			for(long long i=1;i<=n;i++){
				if(s[i].c>=s[i].a&&s[i].c>=s[i].b){
					v+=1;
					ss[v]=min(s[i].c-s[i].a,s[i].c-s[i].b);
				}
			}
			sort(ss+1,ss+v+1);
			for(long long i=1;i<=s3-m;i++){
				ans-=ss[i];
			}
		}
		printf("%lld\n",ans);
		for(long long i=1;i<=n;i++){
			ss[i]=0;
		}
	}
	return 0;
}
