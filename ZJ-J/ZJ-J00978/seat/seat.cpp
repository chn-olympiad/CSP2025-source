#include<bits/stdc++.h>
using namespace std;
int qz(int a,int b){
	double fz=a,fm=b;
	if((fz/fm)-(a/b)>0)return a/b+1;
	else return a/b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int sum=n*m;
	int a1,cnt=1;
	scanf("%d",&a1);
	for(int i=2;i<=sum;i++){
		int x;
		scanf("%d",&x);
		if(x>a1)cnt++;
	}
	int l=qz(cnt,n);
	printf("%d ",l);
	if(l%2==1){
		if(cnt%n==0)printf("%d",n);
		else printf("%d",cnt%n);
	}
	else{
		if(n-cnt%n==0)printf("1");
		printf("%d",n-cnt%n+1);
	}
	return 0;
}
/*
2 2 
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/
