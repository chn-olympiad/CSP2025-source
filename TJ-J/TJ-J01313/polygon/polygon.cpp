#include<bits/stdc++.h>
using namespace std;
int nm[10005];
//int fro(int k,int b,int n,int j,int mmm,int nnn){
//	int ans;
//	if(k==1){
//		if(mmm*j>nnn) return 1;
//		else return 0;
//	}
//	for(int i=b;i<n;i++){
//		ans+=fro(k-1,b+1,n,j,min(mmm,nm[i]),max(nnn,nm[i]));
//	}return ans;
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ans=0;
	int n;scanf("%d",&n);
	int a=0;
	for(int i=0;i<n;i++){
		scanf("%d",&nm[i]);
		a=max(a,nm[i]);
	}
//	if(a<=2){
		printf("%d",n*(n-1)/2);
//	}else{
//		for(int i=3;i<=n;i++){
//			ans+=fro(i,1,n,i,INT_MAX,0);
//		}printf("\n%d",ans);
//	}
	return 0;
}
