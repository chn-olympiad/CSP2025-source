#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int a,b,n,k,pkr,l,jqc,mr,pd,sum;
int e[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&e[i]);
	}
	pkr=-1;
	l=1;
	for(int i=1;i<=n;i++){
		pd=1;
		for(int j=l;j<=i;j++){
			jqc=-1;
			for(int u=j;u>=l;u--){
				if(jqc==-1)jqc=e[u];
				else jqc=(jqc^e[u]);
				if(jqc==k){
					mr=j;
					pd=0;
					break;
				}
			}
			if(pd==0)break;
		}
		if(pd==0){
			sum++;	
			i=mr;
			l=mr+1;
			pkr=-1;	
		}
	}
	printf("%d",sum);
	return 0;
}
