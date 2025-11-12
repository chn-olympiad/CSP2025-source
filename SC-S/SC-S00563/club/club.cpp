#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+2;
int t,n;
int aa=n/2,bb=n/2,cc=n/2;
struct node{
	int a1,a2,a3;
	int _,maxk,tmax,minn;
	bool r=0;
}a[N]; 
int ans;
int tmax1(int x){
	if(!aa && !cc) return a[x].a2;
	if(!bb && !cc) return a[x].a1;
	if(!aa && !bb) return a[x].a3;
	if(aa==0) return max(a[x].a2,a[x].a3);
	if(bb==0) return max(a[x].a1,a[x].a3);
	if(cc==0) return max(a[x].a2,a[x].a1);
}
void _k(int x){
	a[x].maxk=max(a[x].a1,max(a[x].a2,a[x].a3));
	a[x].minn=min(a[x].a1,min(a[x].a2,a[x].a3));
	a[x]._=a[x].maxk-a[x].minn;
}
bool cmp1(node x,node y){
	return x._==y._ ? x.maxk>y.maxk : x._>y._;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		aa=n/2,bb=n/2,cc=n/2;
		memset(a,0,n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].a1,&a[i].a2,&a[i].a3);
			_k(i);
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(a[i].maxk==a[i].a1&&aa){
				ans+=a[i].maxk;
				a[i].r=1;
				aa--;
				continue;
			}
			if(a[i].maxk==a[i].a2&&bb){
				ans+=a[i].maxk;
				a[i].r=1;
				bb--;
				continue;

			}
			if(a[i].maxk==a[i].a3&&cc){
				ans+=a[i].maxk;
				a[i].r=1;
				cc--;
				continue;
			}
			if(aa==0) a[i].a1=0;
			if(bb==0) a[i].a2=0;
			if(cc==0) a[i].a3=0;
		}
		for(int i=1;i<=n;i++){
			if(a[i].r==0)
			a[i].tmax=tmax1(i);
		}
		for(int i=1;i<=n;i++){
			if(a[i].r==0){
				if(a[i].tmax==a[i].a1){
					ans+=a[i].tmax;
					a[i].r=1;
					aa--;
					continue;
				}
				if(a[i].tmax==a[i].a2){
					ans+=a[i].tmax;
					a[i].r=1;
					bb--;
					continue;
				}
				if(a[i].tmax==a[i].a3){
					ans+=a[i].tmax;
					a[i].r=1;
					cc--;
					continue;
				}
			}
		else{
			continue;
		}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}