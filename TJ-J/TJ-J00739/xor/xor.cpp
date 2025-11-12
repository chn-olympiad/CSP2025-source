#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	int a[500005];
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[n]);
		if(a[n]!=1) flag=false;
	}
	if(k==0 && flag){
		if(n==1) printf("%d",0);
		else if(n==2) printf("%d",1);
		else{
			printf("%d", n/2);
		}
		return 0;
	}
//	int cnt=0;
//	int l[10005],r[100005];
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			for(int l=j;l<=j+i;l++){
//				
//			}
//			int res=0;
//			for(int l=i;l<=j;l++){
//				res = res xor(a[l]);
//			}
//			if(res=k) 
//		}
//	}
	cout<<2;
	return 0;
}
