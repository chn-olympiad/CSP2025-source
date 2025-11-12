#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int mod=998244353;
int n,t;
struct node{
	int a,b,c,d;
}a[N];
bool cmp(node a,node b){
	return a.d>b.d;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
	int sum[4]={0},ans=0;
	for(int i=1;i<=n;i++){
		int _=min(min(a[i].a,a[i].b),a[i].c);
		ans+=_;
		a[i].a-=_;a[i].b-=_;a[i].c-=_;
		if(a[i].a==0)  a[i].d=abs(a[i].b-a[i].c);
		else if(a[i].b==0)  a[i].d=abs(a[i].a-a[i].c);
		else  a[i].d=abs(a[i].b-a[i].a);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].b>=a[i].c&&a[i].b>=a[i].a){
			if(sum[2]<n/2)  ans+=a[i].b,sum[2]++;
			else if(a[i].a>=a[i].c)  ans+=a[i].a,sum[1]++;
			else  ans+=a[i].c,sum[3]++;
		}else if(a[i].a>=a[i].c&&a[i].a>=a[i].b){
			if(sum[1]<n/2)  ans+=a[i].a,sum[1]++;
			else if(a[i].b>=a[i].c)  ans+=a[i].b,sum[2]++;
			else  ans+=a[i].c,sum[3]++;
		}else{
			if(sum[3]<n/2)  ans+=a[i].c,sum[3]++;
			else if(a[i].b>=a[i].a)  ans+=a[i].b,sum[2]++;
			else  ans+=a[i].a,sum[1]++;
		}
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
