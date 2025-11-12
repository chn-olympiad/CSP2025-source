#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define MAXN 10010
int b[MAXN],c[MAXN];
struct bata{
	int a1,a2,a3;
};
bata a[MAXN];
signed main(){
	int t;
	scanf("%lld",&t);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int r=1;r<=t;r++){
		int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].a1,&a[i].a2,&a[i].a3);
		for(int i=1;i<=n;i++){
			int sum=max(a[i].a1,a[i].a2);
			sum=max(sum,a[i].a3);
			b[i]=sum;
			if(sum==a[i].a1) c[i]=1;
			if(sum==a[i].a2) c[i]=2;
			if(sum==a[i].a3) c[i]=3;
		}
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=n;j++){
				if(c[i]==1) s1++;
				if(c[i]==2) s2++;
				if(c[i]==3) s3++;
			}
		int ans=0;
		/*
		if(s1>n/2){
			sort(b+1,b+s1+1);
			ans=0;
			int s4=n/2,e=0;
			sort(b+1,b+s1+1);
			for(int j=1;j<=s1;j++)ans+=b[j];
			for(int j=1;j<=s1-s4;j++) e+=b[j];
			ans=ans-e;
		}
		else if(s2>n/2){
			sort(b+1,b+s1+1);
			ans=0;
			int s4=n/2,e=0;
			sort(b+1,b+s2+1);
			for(int j=1;j<=s2;j++) ans+=b[j];
			for(int j=1;j<=s2-s4;j++) e+=b[j];
			ans=ans-e;
		}
		else if(s3>n/2){
			sort(b+1,b+s1+1);
			ans=0;
			int s4=n/2,e=0;
			sort(b+1,b+s3+1);
			for(int j=1;j<=s3;j++) ans+=b[j];
			for(int j=1;j<=s3-s4;j++) e+=b[j];
			ans=ans-e;
		}
		*/
		for(int i=1;i<=n;i++) ans+=b[i];
		printf("%d\n",ans);	
	}
	return 0;
}
