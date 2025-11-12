#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,cnt1,cnt2,cnt3,ans;
struct node{
	int d1,d2,d3;
	int maxx,cha,id;
}a[101000];
bool cmp(node x,node y){
	if(x.cha==y.cha)
		return x.maxx>y.maxx;
	return x.cha>y.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].d1,&a[i].d2,&a[i].d3);
			if(a[i].d1>a[i].d2&&a[i].d1>a[i].d3)
				a[i].id=1,a[i].cha=a[i].d1-max(a[i].d2,a[i].d3),a[i].maxx=a[i].d1;
			else if(a[i].d2>a[i].d1&&a[i].d2>a[i].d3)
				a[i].id=2,a[i].cha=a[i].d2-max(a[i].d1,a[i].d3),a[i].maxx=a[i].d2;
			else if(a[i].d3>a[i].d1&&a[i].d3>a[i].d2)
				a[i].id=3,a[i].cha=a[i].d3-max(a[i].d1,a[i].d2),a[i].maxx=a[i].d3;
			else if(a[i].d1==a[i].d2&&a[i].d1>a[i].d3)
				a[i].id=0,a[i].cha=0,a[i].maxx=a[i].d1,ans+=a[i].d1;
			else if(a[i].d1==a[i].d3&&a[i].d1>a[i].d2)
				a[i].id=0,a[i].cha=0,a[i].maxx=a[i].d1,ans+=a[i].d1;
			else if(a[i].d2==a[i].d3&&a[i].d2>a[i].d1)
				a[i].id=0,a[i].cha=0,a[i].maxx=a[i].d2,ans+=a[i].d2;
			else
				a[i].id=0,a[i].cha=0,a[i].maxx=a[i].d1,ans+=a[i].d1;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].id==1){
				if(cnt1*2+2<=n)
					cnt1++,ans+=a[i].d1;
				else if(a[i].d2>=a[i].d3)
					cnt2++,ans+=a[i].d2;
				else
					cnt3++,ans+=a[i].d3;
			}
			else if(a[i].id==2){
				if(cnt2*2+2<=n)
					cnt2++,ans+=a[i].d2;
				else if(a[i].d1>=a[i].d3)
					cnt1++,ans+=a[i].d1;
				else
					cnt3++,ans+=a[i].d3;
			}
			else if(a[i].id==3){
				if(cnt3*2+2<=n)
					cnt3++,ans+=a[i].d3;
				else if(a[i].d1>=a[i].d2)
					cnt1++,ans+=a[i].d1;
				else
					cnt2++,ans+=a[i].d2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
