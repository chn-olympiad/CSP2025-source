#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e5+100;
long long T,n;
struct E{
	long long i1,i2,i3;
}a[N];
int f1=0,f2=0;
long long ans=0;
bool cmp1(E A,E B){
	return A.i1>B.i1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans=0;
		f1=0;
		f2=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].i1,&a[i].i2,&a[i].i3);
			if(a[i].i3!=0)f1=1,f2=1;
			if(a[i].i2!=0)f1=1;
		}
		if(f1==0){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].i1;
			}
			cout<<ans<<"\n";
		}
//		if(f2==0){
//			
//			return 0;
//		}
//		for(int i=1;i<=n/2;i++){
//			for(int j=1;j<=n/2;j++){
//				int k=n-i-j;
//					if(i!=j&&j!=k&&i!=k){
//						long long sum=a[i][1]+a[j][2]+a[k][3];
//						ans=max(ans,sum);
//					}
//			}
//		}
		else if(n==2){
			ans=max(a[1].i1+a[2].i2,a[1].i1+a[2].i3);
			ans=max(ans,a[1].i2+a[2].i1);
			ans=max(ans,a[1].i2+a[2].i3);
			ans=max(ans,a[1].i3+a[2].i1);
			ans=max(ans,a[1].i3+a[2].i2);
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}
