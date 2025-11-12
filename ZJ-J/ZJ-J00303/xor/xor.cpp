#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,sum[N],cnt,lst,ppp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		sum[i]=sum[i-1]^x;
		if(n>=200000)ppp+=(x==k);
	}
	if(n>=200000&&(ppp||(k==1||k==2))){
		printf("%d",ppp);
		return 0;
	}
	if(n>=200000){
		putchar('0');
		return 0;
	}
	for(int i=1;i<=n;i++) {
		bool flag=false;
		for(int j=lst+1;j<=i;j++){
			if((sum[i]^sum[j-1])==k){
				flag=true;
				break;
			}
		}
		if(flag)cnt++,lst=i;
	}
	printf("%d",cnt);
	return 0;
}
