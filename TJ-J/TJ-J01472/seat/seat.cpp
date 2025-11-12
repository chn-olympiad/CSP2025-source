#include <bits/stdc++.h>
using namespace std;
int n,m,num,sum=0,a=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	num=n*m;
	scanf("%d",&a);
	for(int i=2;i<=num;i++){
		int scare;
		scanf("%d",&scare);
		if(scare>a)sum++;
	} 
	int l=1,h=1;
	l+=sum/n;
	sum++;
	if(l%2==1){
		int k=l-1;
		h=sum-k*n;
	}else{
		int k=l-1;
		h=sum-k*n;
		h=n+1-h;
	}
	printf("%d %d",l,h);
	return 0;
}
