#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long a[4][500001];
long long l[4];
long long p[4][500001];
long long ans;
bool cmp(long long i,long long j){
	return a[0][i]>a[0][j];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ans=0;
		l[0]=l[1]=l[2]=l[3]=0;
		memset(a,0,sizeof(a));memset(p,0,sizeof(p));
		for(long long i=1;i<=n;i++){
			scanf("%lld %lld %lld",&a[1][i],&a[2][i],&a[3][i]);
			a[0][i]=-1;
			long long ti=0,qti=0;
			for(long long j=1;j<=3;j++){
				if(a[ti][i]<a[j][i])ti=j;
			}
			for(long long j=1;j<=3;j++){
				if(ti==j)continue;
				if(a[qti][i]<a[j][i])qti=j;
			}
			a[0][i]=a[ti][i]-a[qti][i];
			ans+=a[ti][i];
			p[ti][++l[ti]]=i;
		}
		long long ti=0;
		for(long long i=1;i<=3;i++){
			if(l[i]>n/2)ti=i;
		}
//		for(long long i=1;i<=n;i++){
//			printf("%lld ",a[0][i]);
//		}
//		cout<<"\n";
//		printf ("%lld %lld %lld\n",l[1],l[2],l[3]);
		if(ti){
			sort(p[ti]+1,p[ti]+1+l[ti],cmp);
			while(l[ti]>n/2){
				ans-=a[0][p[ti][l[ti]]];
				l[ti]--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}