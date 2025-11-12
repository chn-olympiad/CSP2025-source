#include<bits/stdc++.h>
using namespace std;
struct p{
	long long a,b,c;
}mp[100005];
long long t,n,maxn,zj,ans1,ans2;
void check(int sum1,int sum2,int sum3,long long step,long long ans){
	if(sum1>zj||sum2>zj||sum3>zj){
		return ;
	}
	if(step==n+1){
		maxn=max(ans,maxn);
		return ;
	}
	check(sum1+1,sum2,sum3,step+1,ans+mp[step].a);
	check(sum1,sum2+1,sum3,step+1,ans+mp[step].b);
	check(sum1,sum2,sum3+1,step+1,ans+mp[step].c);
	return ;
}
bool cmp1(p x,p y){
	return x.a>y.a;
}
bool cmp2(p x,p y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		zj=n/2;
		maxn=0,ans1=0,ans2=0;
		for(int j=1;j<=n;j++){
			scanf("%lld%lld%lld",&mp[j].a,&mp[j].b,&mp[j].c);
			if(mp[j].c==0&&mp[j].b==0){
				ans1++;
			}
			else if(mp[j].c==0)ans2++;
		}
		if(ans1==n){
			sort(mp+1,mp+n+1,cmp1);
			for(int j=1;j<=zj;j++){
				maxn+=mp[j].a;
			}
		}
		else if(ans2==n){
			for(int j=1;j<=n;j++){
				mp[j].c=mp[j].a-mp[j].b;
			}
			sort(mp+1,mp+1+n,cmp2);
			for(int j=1;j<=zj;j++){
				maxn+=mp[j].a;
			}
			for(int j=zj+1;j<=n;j++){
				maxn+=mp[j].b;
			}
		}
		else{
			check(0,0,0,1,0);
		}
		printf("%lld\n",maxn);
	}
	
	return 0;
}
