#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	scanf("%d %d",&n,&k);
	int r[n+5];
    for(int i=1;i<=n;i++){
         scanf("%d",&r[i]);
    	if(r[i]==k)s++;
	}
    if(k==0){
    	printf("%d",s);
    	return 0;
	}
    printf("%d",s);
	return 0;
}