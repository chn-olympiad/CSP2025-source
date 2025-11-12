#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+100;
int t,n,a[N][5];
int a1[N],a2[N],a3[N];
int tot1,tot2,tot3;
int m[N],totm;
int ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=tot1=tot2=tot3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])  a1[++tot1]=i,ans+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])  a2[++tot2]=i,ans+=a[i][2];
			else a3[++tot3]=i,ans+=a[i][3];
		}
		if(tot1<=n/2&&tot2<=n/2&&tot3<=n/2){
			printf("%d\n",ans);
			continue;
		}
		if(tot1>n/2){
			totm=tot1;
			for(int i=1;i<=tot1;i++) m[i]=a[a1[i]][1]-max(a[a1[i]][2],a[a1[i]][3]);
		}
		if(tot2>n/2){
			totm=tot2;
			for(int i=1;i<=tot2;i++) m[i]=a[a2[i]][2]-max(a[a2[i]][1],a[a2[i]][3]);
		}
		if(tot3>n/2){
			totm=tot3;
			for(int i=1;i<=tot3;i++) m[i]=a[a3[i]][3]-max(a[a3[i]][1],a[a3[i]][2]);
		}
		sort(m+1,m+totm+1);
		for(int i=1;i<=totm-n/2;i++) ans-=m[i];
		printf("%d\n",ans);
	}
	return 0;
}
