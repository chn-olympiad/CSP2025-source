#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	k=a[1];
	sort(1+a,1+n*m+a,cmp);
	int i=1,lin=1;
	while(a[i]!=k){
		if(i%n==0) lin++;
		i++;
	}
	printf("%d ",lin);
	if(lin%2==1){
		printf("%d",i-(lin-1)*n);
	}
	else{
		printf("%d",lin*n-i+1);
	}
	return 0;
}