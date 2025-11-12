#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,x,y,z,cnt,a[N][4],sum1,sum2,sum3;
struct node{
	ll d,f;
}t[N];
int cmp(node x,node y){
	return x.d<y.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		cnt=0;
		sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&x,&y,&z);
			a[i][1]=x;
			a[i][2]=y;
			a[i][3]=z;
			ll sum=x+y+z;
			x=min(min(a[i][1],a[i][2]),a[i][3]);
			z=max(max(a[i][1],a[i][2]),a[i][3]);
			y=sum-x-z;
			t[i].d=z-y;
			cnt+=z;
			if(z==a[i][1])sum1++,t[i].f=1;
			else if(z==a[i][2])sum2++,t[i].f=2;
			else sum3++,t[i].f=3;
//			cout<<x<<' '<<y<<' '<<z<<' '<<t[i].d<<endl;
		}
		sort(t+1,t+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<t[i].d<<' '<<t[i].f<<endl;
//		}
		int flag=0;
		int p=max(sum1,max(sum2,sum3));
		if(p>n/2){
			if(sum1>n/2)flag=1;
			if(sum2>n/2)flag=2;
			if(sum3>n/2)flag=3;
			int val=0;
			for(int i=1;i<=n&&val<p-n/2;i++){
				if(t[i].f==flag)cnt-=t[i].d,val++;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
} 
