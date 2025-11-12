#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,b1[100005],b2[100005],b3[100005],T,top1,top2,top3,ans;
struct st{
	int v1,v2,v3,c;
}a[100005],aa[100005];
bool cmp(st x,st y){
	return x.c<y.c;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>T;
	while(T--){
		top1=0,top2=0,top3=0,ans=0;
		memset(b1,0,sizeof b1);
		memset(b2,0,sizeof b2);
		memset(b3,0,sizeof b3);
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i].v1>>a[i].v2>>a[i].v3;
		for(int i=1;i<=n;++i){
			if(a[i].v1>=a[i].v2&&a[i].v1>=a[i].v3) b1[++top1]=i;
			else if(a[i].v2>=a[i].v1&&a[i].v2>=a[i].v3) b2[++top2]=i;
			else if(a[i].v3>=a[i].v1&&a[i].v3>=a[i].v2) b3[++top3]=i;
		}
		for(int i=1;i<=top1;++i) ans+=a[b1[i]].v1;
		for(int i=1;i<=top2;++i) ans+=a[b2[i]].v2;
		for(int i=1;i<=top3;++i) ans+=a[b3[i]].v3;
		if(top1>n/2){
			for(int i=1;i<=n;++i) a[i].c=1e18;
			for(int i=1;i<=top1;++i){
				int x=b1[i];
				a[x].c=min(a[x].v1-a[x].v2,a[x].v1-a[x].v3);
			}
			sort(a+1,a+n+1,cmp);
			int ma=top1-n/2;
			for(int i=1;i<=ma;++i) ans-=a[i].c;
		}
		
		else if(top2>n/2){
			for(int i=1;i<=n;++i) a[i].c=1e18;
			for(int i=1;i<=top2;++i){
				int x=b2[i];
				a[x].c=min(a[x].v2-a[x].v1,a[x].v2-a[x].v3);
			}
			sort(a+1,a+n+1,cmp);
			int ma=top2-n/2;
			for(int i=1;i<=ma;++i) ans-=a[i].c;
		}
		
		else if(top3>n/2){
			for(int i=1;i<=n;++i) a[i].c=1e18;
			for(int i=1;i<=top3;++i){
				int x=b3[i];
				a[x].c=min(a[x].v3-a[x].v1,a[x].v3-a[x].v2);
			}
			sort(a+1,a+n+1,cmp);
			int ma=top3-n/2;
			for(int i=1;i<=ma;++i) ans-=a[i].c;
		}
		cout<<ans<<"\n";
	}
}
