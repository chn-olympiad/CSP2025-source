#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005],b[100005],c[100005],A[100005],B[100005],C[100005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0,A[0]=0,B[0]=0,C[0]=0;
		for(int i=1;i<=n;i++){
		  scanf("%d%d%d",&a[i],&b[i],&c[i]);
		  if(a[i]>=b[i]&&a[i]>=c[i]){
		  	ans+=a[i];
		  	A[++A[0]]=a[i]-max(b[i],c[i]);
		  }else
		  if(b[i]>=a[i]&&b[i]>=c[i]){
		  	ans+=b[i];
		  	B[++B[0]]=b[i]-max(a[i],c[i]);
		  }else ans+=c[i],C[++C[0]]=c[i]-max(a[i],b[i]);
	}
//	   cout<<A[0]<<" "<<B[0]<<" "<<C[0]<<endl;
	    if(A[0]<=n/2&&B[0]<=n/2&&C[0]<=n/2){
	   // 	cout<<n/2<<endl;
	    	printf("%d\n",ans);
	    	continue;
		}
	//	cout<<1<<endl;
		if(A[0]>n/2){
			sort(A+1,A+1+A[0]);
			for(int i=1;i<=A[0]-n/2;i++)ans-=A[i];
		}
		if(B[0]>n/2){
			sort(B+1,B+1+B[0]);
			for(int i=1;i<=B[0]-n/2;i++)ans-=B[i];
		}
		if(C[0]>n/2){
			sort(C+1,C+1+C[0]);
			for(int i=1;i<=C[0]-n/2;i++)ans-=C[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
//1
//10
//2020 14533 18961
//2423 15344 16322
//1910 6224 16178
//2038 9963 19722
//8375 10557 5444
//3518 14615 17976
//6188 13424 16615
//8769 509 4394
//958 3195 9953
//16441 5313 10926

