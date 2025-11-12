#include<bits/stdc++.h>
using namespace std;
const int mxn=1e5+2;
struct num{
	int a,b,c;
}a[mxn];
int t,n,idx,lim,ans=-0x3f3f3f3f;
int cnt1,cnt2,cnt3;
inline bool cmp(num a,num b){
	if(idx==1) return a.a!=b.a?a.a>b.a:(a.b!=b.b?a.b>b.b:a.c>b.c);
	else return a.a!=b.a?a.a<b.a:(a.b!=b.b?a.b<b.b:a.c<b.c);
}

void sol(){
	int res=0,ai=0,bi=0,ci=0,mx=0;
	for(int i=1;i<=n;i++){
		ai=a[i].a,bi=a[i].b,ci=a[i].c;
		if(cnt1>=lim) ai=-1;
		if(cnt2>=lim) bi=-1;
		if(cnt3>=lim) ci=-1;
		mx=max(max(ai,bi),ci);
		if(mx==ai) res+=ai,cnt1++;
		else if(mx==bi) res+=bi,cnt2++;
		else res+=ci,cnt3++;
	}
	ans=max(ans,res);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		lim=(n>>1);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		for(int i=1;i<=2;i++){
			idx=i;
			cnt1=cnt2=cnt3=0;
			sort(a+1,a+1+n,cmp);
			sol();
		}
		printf("%d\n",ans);
		ans=-0x3f3f3f3f;
	}
}