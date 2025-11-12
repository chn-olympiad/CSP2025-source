#include<bits/stdc++.h>
#include<cstdio>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,cnta,cntb,cntc,ans;
struct node{
	int a,b,c;
}stu[N];
struct sol{
	int id,val;
}a[N],b[N],c[N];
bool cmp(sol x,sol y){
	return x.val<y.val;
}
void init(){
	cnta=cntb=cntc=ans=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		int lim=n/2;
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&stu[i].a,&stu[i].b,&stu[i].c);
		for(int i=1;i<=n;i++){
			if(stu[i].a>=max(stu[i].b,stu[i].c)) a[++cnta]=sol{i,stu[i].a},ans+=stu[i].a;
			else if(stu[i].b>=max(stu[i].a,stu[i].c)) b[++cntb]=sol{i,stu[i].b},ans+=stu[i].b;
			else c[++cntc]=sol{i,stu[i].c},ans+=stu[i].c;
		}
		//cout<<ans<<endl;
		if(cnta>lim){
			for(int i=1;i<=cnta;i++) a[i].val=min(stu[a[i].id].a-stu[a[i].id].c,stu[a[i].id].a-stu[a[i].id].b);
			sort(a+1,a+1+cnta,cmp);
			for(int i=1;i<=cnta-lim;i++) ans-=a[i].val;
		}
		else if(cntb>lim){
			for(int i=1;i<=cntb;i++) b[i].val=min(stu[b[i].id].b-stu[b[i].id].a,stu[b[i].id].b-stu[b[i].id].c);
			sort(b+1,b+1+cntb,cmp);
			for(int i=1;i<=cntb-lim;i++) ans-=b[i].val;
		}
		else if(cntc>lim){
			for(int i=1;i<=cntc;i++) c[i].val=min(stu[c[i].id].c-stu[c[i].id].b,stu[c[i].id].c-stu[c[i].id].a);
			sort(c+1,c+1+cntc,cmp);
			for(int i=1;i<=cntc-lim;i++) ans-=c[i].val;
		}
		else{
			ans=ans;
		}
		printf("%lld\n",ans);
		init();
	}
	return 0;
}
/*
*/
