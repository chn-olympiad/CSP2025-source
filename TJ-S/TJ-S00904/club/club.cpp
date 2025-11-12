#include <bits/stdc++.h>
#define ll signed long long
using namespace std;
int const N=1e5+50;
struct node{
	ll num,name;
	bool b=0,no=0,key=0;
}a1[N],a2[N],a3[N],b4[N],b5[N],b6[N],b1[N],b2[N];
ll a4[N],a5[N],a6[N],sum1[N]={0},sum2[N]={0},sum3[N]={0},ans=0;
bool cmp(node an,node bn){
	return an.num<bn.num;
}
int main(){
	ll n,t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		for(int j=1;j<=n;j++){
			ans=0;
			scanf("%lld %lld %ldd",&a1[j].num,&a2[j].num,&a3[j].num);
			b1[j].num=a1[j].num;
			b2[j].num=a2[j].num;
			a1[j].name=j;
			a2[j].name=j;
			a3[j].name=j;
			a4[j]=a2[j].num-a1[j].num;
			b4[j].num=a4[j];
			b4[j].name=j;
			b5[j].num=a3[j].num-a1[j].num;
			b5[j].name=j;
			b6[j].num=a3[j].num-a2[j].num;
			b6[j].name=j;
		}
		if(a2[1].num==a3[1].num==0){
			sort(a1+1,a1+1+n,cmp);
			for(int j=n/2+1;j<=n;j++){
				ans+=a1[j].num;
			}
			cout<<ans<<endl;
			continue;
		}
		sort(a1+1,a1+1+n,cmp);
		for(int j=1;j<=n;j++){
			sum1[j]+=sum1[j-1]+a1[j].num;	
		}
		int mid=n/2;
		ans+=sum1[n]-sum1[mid];
		for(int j=n;j>=mid+1;j--){
			a1[j].b=1;
			ll n1=a1[j].name;
			b4[n1].b=1;
		}
		for(int j=1;j<=n;j++){
			if(b4[j].b==1){
				b4[j].key=1;
			}
		}
		sort(b4+1,b4+n+1,cmp);
		int nn=n/2;
		for(int j=n;j>=1;j--){
			if(b4[j].key==1){
				int n1=b4[j].name;
				a2[n1].num=b4[j].num+a1[nn].num;
				nn--;
				a2[j].no=1;
			}
		}
		sort(a2+1,a2+1+n,cmp);
		for(int j=1;j<=n;j++){
			sum2[j]+=sum2[j-1]+a2[j].num;
		}
		ans+=sum2[n]-sum2[mid];
		for(int j=n;j>=n/2+1;j--){
			int n1=a2[j].name;
			b2[n1].b=1;
			b1[n1].b=0;
		}
		for(int j=n/2;j>=1;j--){
			int n1=a2[j].name;
			b1[n1].b=1;
			b2[n1].b=0;
		}
		for(int j=1;j<=n;j++){
			if(b1[j].b==0)b5[j].key=1;
			if(b2[j].b==0)b6[j].key=1;
		}
		for(int j=n;j>=1;j--){
			if(b5[j].key==1){
				int n1=b5[j].name;
				a3[n1].num=b5[j].num;
			}
		}
		for(int j=n;j>=1;j--){
			if(b6[j].key==1){
				int n1=b6[j].name;
				a3[n1].num=b6[j].num;
			}
		}
		sort(a3+1,a3+1+n,cmp);
		for(int j=n;j>=n/2+1;j--){
			if(a3[j].num>0){
				ans+=a3[j].num;
			}else{
				break;
			}
		}
		printf("%lld\n",ans);
		for(int j=1;j<=n;j++){
			sum1[j]=0;
			sum2[j]=0;
			sum3[j]=0;
			a1[j].num=0;
			a2[j].num=0;
			a3[j].num=0;
			a4[j]=0;
			a5[j]=0;
			a5[j]=0;
			b1[j].num=0;
			b2[j].num=0;
			b6[j].num=0;
			b4[j].num=0;
			b5[j].num=0;
		}
	} 
	return 0;
}
