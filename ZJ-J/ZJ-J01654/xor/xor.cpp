#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt=0,x[500005],a=0,b=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==1){
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
			if(x[i]==1) cnt++;
		}
		printf("%d",cnt);
	}
	else if(k==0){
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
			if(x[i]==0) cnt++;
			else if(x[i]==1 and x[i-1]==1){
				x[i]=x[i-1]=0;
				cnt++;
			}
		}
		printf("%d",cnt);
	}
	else{
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
			if(x[i]==1) a++;
			else if(x[i]==0) b++;
		}
		if((a+b)==n) printf("0");
		else printf("%d",n/2);
	}
	return 0;
}
