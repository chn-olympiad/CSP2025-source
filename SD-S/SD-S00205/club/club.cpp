#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct NODE{
	int a;
	int b;
	int c;
	int id;
}p[N];
bool cmp(NODE x,NODE y){
	return x.a-x.b>y.a-y.b;
}
void solve()
{
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);
		p[i].id=i;
	}
	int ans=0,s=0;
	int tot1=0,tot2=0,tot3=0;
	for(int i=1;i<=n;i++){
		s=s+max({p[i].a,p[i].b,p[i].c});
		if(p[i].a>=p[i].b&&p[i].a>=p[i].c){
			tot1++;
			ans+=p[i].a;
		}
		else if(p[i].b>=p[i].c&&p[i].b>=p[i].a){
			tot2++;
			ans+=p[i].b;
		}
		else tot3++,ans+=p[i].c;
	}
	if(tot1<=n/2&&tot2<=n/2&&tot3<=n/2){
		printf("%lld\n",ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(tot1>n/2){
			p[i].a=p[i].a;
			p[i].b=max(p[i].b,p[i].c);
		}
		else if(tot2>n/2){
			int t=max(p[i].a,p[i].c);
			p[i].a=p[i].b;
			p[i].b=t;
		}
		else if(tot3>n/2){
			int t=max(p[i].a,p[i].b);
			p[i].a=p[i].c;
			p[i].b=t;
		}
	}
	sort(p+1,p+n+1,cmp);
	ans=0;
	for(int i=1;i<=n;i++){
		if(i<=n/2)ans+=p[i].a;
		else ans+=p[i].b;
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
