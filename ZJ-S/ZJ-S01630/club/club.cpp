#include<bits/stdc++.h>
using namespace std;
struct T{
	int a1;
	int a2;
	int a3;
}a[100010];
int bz;
bool cmp(T x,T y){
	if(bz==1) return x.a1-max(x.a2,x.a3)>y.a1-max(y.a2,y.a3);
	if(bz==2) return x.a2-max(x.a1,x.a3)>y.a2-max(y.a1,y.a3);
	if(bz==3) return x.a3-max(x.a1,x.a2)>y.a3-max(y.a1,y.a2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int e1=0,e2=0,e3=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].a1);
			scanf("%d",&a[i].a2);
			scanf("%d",&a[i].a3);
			if(a[i].a1>a[i].a2 && a[i].a1>a[i].a3) e1++;
			else if(a[i].a2>a[i].a1 && a[i].a2>a[i].a3) e2++;
			else e3++;
		}
		int zz=n/2;
		if(max(max(e1,e2),e3)<=zz){
			long long ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(a[i].a1,max(a[i].a2,a[i].a3));
			}
			printf("%d\n",ans);
			continue;
		}
		if(e1>e2 && e1>e3) bz=1;
		else if(e2>e1 && e2>e3) bz=2;
		else bz=3;
		sort(a+1,a+n+1,cmp);
		int cnt=0;
		long long ans2=0;
		for(int i=1;i<=n;i++){
			ans2+=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(bz==1 && a[i].a1>a[i].a2 && a[i].a1>a[i].a3) cnt++;
			if(bz==2 && a[i].a2>a[i].a1 && a[i].a2>a[i].a3) cnt++;
			if(bz==3 && a[i].a3>a[i].a2 && a[i].a3>a[i].a1) cnt++;
			if(cnt>zz){
				ans2-=max(a[i].a1,max(a[i].a2,a[i].a3));
				if(bz==1) ans2+=max(a[i].a2,a[i].a3);
				if(bz==2) ans2+=max(a[i].a1,a[i].a3);
				if(bz==3) ans2+=max(a[i].a1,a[i].a2);
			}
		}
		printf("%d\n",ans2);
	}
	return 0;
}
