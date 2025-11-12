#include <bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i;
	for(i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=find(a,a+n*m,p)-a;
	//printf("x=%d\n",x);
	int c=(x-1)/n+1;
	int r;
	if(c%2==0){
		r=n-((x-1)%n);
	}else{
		r=(x-1)%n+1;
	}
	printf("%d %d",c,r);
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/