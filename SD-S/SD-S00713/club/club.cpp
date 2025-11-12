#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+9;
struct node{
	LL a,b,c;
};
node s[N];
struct P{
	LL dx,pl,m;
};
P p[N];
LL n;
bool cmp1(P x,P y){
	return x.dx>y.dx;
}
void solve(){
	LL ans=0,cnt1=0,cnt2=0,cnt3=0,i1=0,i2=0,i3=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&s[i].a,&s[i].b,&s[i].c);
		p[i].pl=i;
		LL mx=max(s[i].a,max(s[i].b,s[i].c));p[i].m=mx;
		if(mx==s[i].a)p[i].dx=min(mx-s[i].b,mx-s[i].c);
		if(mx==s[i].b)p[i].dx=min(mx-s[i].a,mx-s[i].c);
		if(mx==s[i].c)p[i].dx=min(mx-s[i].b,mx-s[i].a);
	}
	sort(p+1,p+n+1,cmp1);
	for(int i=1;i<=n;i++){
		LL t=p[i].pl;
		if(s[t].a==p[i].m){
			if(cnt1>=n/2)ans+=p[i].m-p[i].dx;
			else{
				cnt1++;
				ans+=p[i].m;
			}
		}
		else if(s[t].b==p[i].m){
			if(cnt2>=n/2)ans+=p[i].m-p[i].dx;
			else{
				cnt2++;
				ans+=p[i].m;
			}
		}
		else if(s[t].c==p[i].m){
			if(cnt3>=n/2)ans+=p[i].m-p[i].dx;
			else{
				cnt3++;
				ans+=p[i].m;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
