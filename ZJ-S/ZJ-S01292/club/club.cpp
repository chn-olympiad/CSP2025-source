#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
struct Man{
	int rank,d1,d2,t1,t2,t3,bas;
}a[100005];
struct Car{
	int rank,sc;
}b[5];
bool cmp1(Car c1,Car c2){
	return c1.sc>c2.sc;
}
bool cmp2(Man m1,Man m2){
	return m1.d1==m2.d1?(m1.d2>m2.d2):(m1.d1>m2.d1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int qqq=1;qqq<=T;qqq++){
		scanf("%lld",&n);
		int cnt[5]={},AC=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&b[1].sc,&b[2].sc,&b[3].sc);
			b[1].rank=1,b[2].rank=2,b[3].rank=3;
			sort(b+1,b+4,cmp1);
			a[i].d1=b[1].sc-b[2].sc,a[i].d2=b[2].sc-b[3].sc,a[i].rank=i;
			a[i].t1=b[1].rank,a[i].t2=b[2].rank,a[i].t3=b[3].rank,a[i].bas=b[3].sc;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(cnt[a[i].t1]!=n/2){
				cnt[a[i].t1]++;
				AC+=a[i].bas+a[i].d1+a[i].d2;
			} 
			else{
				if(cnt[a[i].t2]!=n/2){
					cnt[a[i].t2]++;
					AC+=a[i].bas+a[i].d2;
				}
				else{
					cnt[a[i].t3]++;
					AC+=a[i].bas;
				}
			}
		}
		printf("%lld\n",AC);
	}
	return 0;
}
