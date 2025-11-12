#include<bits/stdc++.h>
using namespace std;
int n,m,t,tt,awa=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d %d",&n,&m,&t);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&tt);
		if(tt>t) awa++;
	}
	int qwq=awa/n+1;
	if(qwq%2==1){
		printf("%d %d",qwq,awa+1-(qwq-1)*n);
	}
	else{
		printf("%d %d",qwq,n+1-(awa+1-(qwq-1)*n));
	}
	return 0;
}
//made by S_A_T_E_L_L_I_T_E(luogu_737070)
//maybe 100
//I love phigros
