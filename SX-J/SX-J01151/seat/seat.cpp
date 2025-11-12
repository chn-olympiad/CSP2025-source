#include<bits/stdc++.h>
using namespace std;
int n,s[105],minio,m,x,y;
int find(int num){
	int l=1,r=n*m+1,mid,i=0;
	while(l<r){
		i++;
		mid=(l+r)/2;
		if(s[mid]<num){
			r=mid-1;
		}else l=mid+1;
	}
//	printf("%d\n",i);
	return r;
}
bool check(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m*n;i++){
    	scanf("%d",&s[i]);
    }
    minio=s[1];
    sort(s+1,s+n*m+1,check);
    int ubu=find(minio);
    x=ubu/n+1;
    y=ubu%n;
    if((x+1)%2==1){
    	y=n-y+1;
	}
	if(ubu<=n){
		y--;
		x--;
	}
//	printf("minio:%d ubu:%d\n",minio,ubu);
    printf("%d %d\n",x,y);
//    for(int i=0;i<=20;i++){
//    	printf("%d\n",s[i]);
//    }
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
/*
2 2
98 99 100 97
*/
/* 
2 2
99 100 97 98
*/
