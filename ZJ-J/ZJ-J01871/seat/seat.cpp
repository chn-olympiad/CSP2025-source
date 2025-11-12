#include<bits/stdc++.h>
using namespace std;
int c[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int r,n,m,pm,djz,gs,ls,hs;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",&c[i]);
	}
	r=c[0];
	sort(c,c+m*n,cmp);
	for(int i=0;i<n*m;i++){
		if(c[i]==r){
			pm=i+1;
		}
	}
	djz=pm/(2*n);
	gs=pm%(2*n);
	if(gs==0){
		gs=2*n;
	}
	if(gs<=n){
		ls=2*djz+1;
		hs=gs;
	}else{
		ls=2*djz+2;
		hs=1+gs-n;
	}
	printf("%d %d",ls,hs);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
