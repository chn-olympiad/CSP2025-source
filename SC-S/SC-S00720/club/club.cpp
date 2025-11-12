#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n,xz,cg,cgds;
int bm[5],bmr[5][201000],lscc[201000];
int sum;
struct node{
	int r,sun;
}ren[201000];


signed main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);xz=n/2; 
		cg=0; sum=0; cgds=0;
		
		for(int i=1;i<=n;i++){
			int aa,bb,cc;
			scanf("%lld%lld%lld",&aa,&bb,&cc);
			int mx=max(aa,max(bb,cc));int cmx;
			if(mx==aa){
				cmx=max(bb,cc);
				bm[1]++; bmr[1][bm[1]]=i;
			}else if(mx==bb){
				cmx=max(aa,cc);
				bm[2]++; bmr[2][bm[2]]=i;
			}else if(mx==cc){
				cmx=max(aa,bb);
				bm[3]++; bmr[3][bm[3]]=i;
			}
			sum+=mx;
			ren[i].r=i; ren[i].sun=mx-cmx;
		}
		
		if(bm[1]>xz) cg=1;
		else if(bm[2]>xz) cg=2;
		else if(bm[3]>xz) cg=3;
		if(cg==0){
			printf("%lld\n",sum);
			for(int i=1;i<=3;i++) bm[i]=0;
			continue;
		}
		
		cgds=bm[cg]-xz;
		for(int i=1;i<=bm[cg];i++){
			lscc[i]=ren[bmr[cg][i]].sun;
		}sort(lscc+1,lscc+bm[cg]+1);
		for(int i=1;i<=cgds;i++){
			sum-=lscc[i];
		}
		printf("%lld\n",sum);
		for(int i=1;i<=3;i++){
			bm[i]=0;
		}
		for(int i=1;i<=bm[cg];i++){
			lscc[i]=0;
		}
	}
	return 0;
}