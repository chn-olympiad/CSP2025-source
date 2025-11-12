#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,z=0;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(k>1){
		printf("0");
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) z++;
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) z++;
		}
	}
	printf("%d",z);
	return 0;
}
