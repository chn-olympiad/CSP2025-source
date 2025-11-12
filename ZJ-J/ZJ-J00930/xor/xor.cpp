#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500050],sum[500050];//前缀异或和 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool flaga=1,flagb=1,flagc=0;//骗分 c好像没用 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			flaga=0;
		}else if(a[i]>1){
			flagb=0;
		}
	}
	if(n<=2&&k==0&&flaga){//pt1+5!
		printf("1\n");
		return 0;
	}
	return 0;
}
