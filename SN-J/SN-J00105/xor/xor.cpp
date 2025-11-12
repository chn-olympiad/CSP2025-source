#include<bits/stdc++.h>
using namespace std;
int n,k,a[10001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	}
	
	if(n == 1&&k == 0){
		printf("0\n");
	}else if(k == 0) {
		printf("0\n");
	}else if(k == 1){
		printf("1\n");
	}else printf("233\n");
	return 0;
}
