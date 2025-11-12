#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e4+10;
int n,m;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//n行m列   先输出列再输出行 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	//特殊判断 n=1,m=1
	if(n==1&&m==1){
		printf("1 1");
		return 0;
	} 
	//特殊性质A a[i]=i a1=1  但从最高分开始做，所以a1坐在最后的位置 
	//特殊性质B a[i]=n*m-i+1  实际i=1 最高分，即a1是最高分 ，坐在第一个位置 
	int cnta=0,cntb=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==i){
			cnta++;
		}
		if(a[i]==n*m-i+1){
			cntb++;
		}
	}
	if(cnta==n*m){
		if(m%2==0){//列为偶数 
			printf("%d 1",m);
		}else{
			printf("%d %d",m,n);
		}
	}else if(cntb==n*m){
		printf("1 1");
	}else{
		int t=a[1];//记录a1数据（没有相同的a1） 
		int pos = 0;
		sort(a+1,a+n*m+1,cmp);
		for(int i=1;i<=n*m;i++){
			if(a[i]==t){
				pos = i;
				break;
			}	
		} 
		int x;
		if(pos%n==0){
			x = pos/n;//第几列
			if(x%2==0){//2n,4n,6n... 
				printf("%d 1",x);
			}else{
				printf("%d %d",x,n);
			}
		}else{
			x = (pos+(n-1))/n;//第几列 
			//第y列第几个数
			int z = pos-(pos/n)*n;
			if(x%2==0){//2n,4n,6n...
				printf("%d %d",x,n-z+1);
			}else{
				printf("%d %d",x,z);
			}
		}
	} 
	return 0;
}
