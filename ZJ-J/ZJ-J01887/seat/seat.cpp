#include<bits/stdc++.h>
using namespace std;
int n,m,num;
int x=1,y=1;
int a[102];
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
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			printf("%d %d",x,y);
			return 0;
		}
		if(x%2){
			if(y==n){
				++x;
			}else{
				++y;
			}
		}else{
			if(y==1){
				++x;
			}else{
				--y;
			}
		}
	}
	return 0;
}