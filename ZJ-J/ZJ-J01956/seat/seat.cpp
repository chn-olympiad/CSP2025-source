#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int tota=n*m;
	for(int i=1;i<=tota;i++){//mn's maxium is 100.
		cin>>a[i];
	}
	int rsc=a[1],rrat;
	sort(a+1,a+tota+1);//from small to big
	for(int i=1;i<=tota;i++){
		if(a[i]==rsc){
			rrat=tota-i+1;//r's rate
			break;
		}
	}
	int c,r,qb;
	c=int(rrat/n);
	if(rrat>c*n){
		c++;//diantile 
	}
	qb=rrat-(c-1)*n-1;
	//printf("第%d名 第%d列 前面有%d个入\n",rrat,c,qb);
	if(c%2==0){
		r=n-qb;	
	}else{
		r=qb+1;
	}
	printf("%d %d",c,r);
	return 0;
}
