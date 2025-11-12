#include<bits/stdc++.h>
using namespace std;
bool pd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	int arr[n*m];
	for(int i=0;i<n*m;i++){
		scanf("%d",&arr[i]);
	}
	int k=arr[0];
	sort(arr,arr+n*m,pd);
//	for(int i=0;i<n;i++){
//		for(int j=i*n;j<n*(i+1);j++){
//			printf("%d ",arr[j]);
//		}
//		printf("\n");
//	}
//	while(l<=r){l=0,r=n*m-1,
//		int mid=(l+r)/2;
//		if(arr[mid]==k){
//			ans=mid+1;break;
//		}else if(arr[mid]>k){
//			r=mid+1;
//		}else if(arr[mid]<k){
//			l=mid-1;
//		}
//		printf("%d,%d\n",l,r);
//	}
//	for(int i=0;i<n*m;i++){
//		if(arr[i]==k){
//			ans=i+1;break;
//		}
//	}

	for(int i=0;i<n;i++){
		for(int j=i*n;j<n*(i+1);j++){
			if(arr[j]==k){
				if((i+1)&1){
					printf("%d %d",i+1,j%n+1);
				}else{
					printf("%d %d",i+1,n-j%n);
				}
				return 0;
			}
		}
	}
//	int hang=ans/n+1,lie=ans%n+1;
//	printf("%d %d",lie,hang);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
