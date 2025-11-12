//SN-J00117 ΑυκΕ³½ 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int sce,pms=1,tmp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&sce);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&tmp);
		if(tmp>sce) pms++;
	}
	int k=pms%(n*2),l=int(pms/(n*2))*2;
	if(k<=n){
		l++;
	}else{
		l+=2;
		k=2*n-k+1;
	}
	printf("%d %d",l,k);
	return 0;
}

