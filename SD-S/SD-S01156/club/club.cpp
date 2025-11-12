#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node {
	int m1,m2,m3,maxx=-1e9,num,maxn,minn,numz,numx;
} a[100010];
bool cmp(node x,node y){
	if(x.maxx==y.maxx){
		if(x.maxn==y.maxn)return x.minn>y.minn;
		return x.maxn>y.maxn;
	}
	return x.maxx>y.maxx;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		int q=0,p=0,k=0,ans=0,s[100010]={0};
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
			a[i].minn=min(a[i].m1,min(a[i].m2,a[i].m3));
			a[i].maxx=a[i].m1,a[i].num=1;
			if(a[i].maxx<a[i].m2)a[i].maxx=a[i].m2,a[i].num=2;
			if(a[i].maxx<a[i].m3)a[i].maxx=a[i].m3,a[i].num=3;
			if(a[i].maxx==a[i].m1){
				if(a[i].minn==a[i].m2){
					a[i].maxn=a[i].m3;
					a[i].numz=3;
					a[i].numx=2;
				}
				if(a[i].minn==a[i].m3){
					a[i].maxn=a[i].m2;
					a[i].numz=2;
					a[i].numx=3;
				}
			}
			if(a[i].maxx==a[i].m2){
				if(a[i].minn==a[i].m1){
					a[i].maxn=a[i].m3;
					a[i].numz=3;
					a[i].numx=1;
				}
				if(a[i].minn==a[i].m3){
					a[i].maxn=a[i].m1;
					a[i].numz=3;
					a[i].numx=2;
				}
			}
			if(a[i].maxx==a[i].m3){
				if(a[i].minn==a[i].m1)a[i].maxn=a[i].m2;
				if(a[i].minn==a[i].m2)a[i].maxn=a[i].m1;
			}
		}
		for(int i=1; i<=n; i++) {
			if(a[i].num==1)q++;
			if(a[i].num==2)p++;
			if(a[i].num==3)k++;
			ans+=a[i].maxx;
		}
		if(q<=n/2&&p<=n/2&&k<=n/2)cout<<ans<<endl;
		else {
			int cnt=0;
			if(n==2) {
				ans=max(a[1].m3+max(a[2].m1,a[2].m2),max(a[1].m1+max(a[2].m2,a[2].m3),a[1].m2+max(a[2].m1,a[2].m3)));
				cout<<ans<<endl;
			}else {
				sort(a+1,a+1+n,cmp);
//				q=p=k=0;
//				bool flag1=flag2=flag3=0;
//				for(int i=1; i<=n; i++) {
//					if(q==n/2)flag1=1;
//					if(p==n/2)flag2=1;
//					if(k==n/2)flag3=1;
//					if(num==1&&flag1==1){
//						if(flag2==1)ans+=a[i].m3,k++;
//						else{
//							if()
//						}
//					}
//				}
				for(int i=n/2+1;i<=n;i++)ans-=a[i].maxx-a[i].maxn;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
