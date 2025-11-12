#include<bits/stdc++.h>
using namespace std;
struct data{
	int num,sit;
}a[105];
int n,m,sitt;
bool cmp(data a,data b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*n+j].num;
			a[(i-1)*n+j].sit=(i-1)*n+j;
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].sit==1){
			sitt=i;
		}
	}
	if(((sitt-1)/n)%2==0){
		cout<<(sitt-1)/n+1<<' '<<(sitt%n==0?m:sitt%n);
	}else{
		cout<<(sitt-1)/n+1<<' '<<(sitt%n==0?1:m-sitt%n+1);
	}
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
