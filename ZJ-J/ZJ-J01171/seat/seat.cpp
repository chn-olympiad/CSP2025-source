#include<bits/stdc++.h>

using namespace std;

const int N=1e2+5;

int a[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int sum=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			sum=i;
			break;
		}
	}
	int x,y;
	x=0,y=1;
	int f=1;
	for(int i=1;i<=sum;i++){
		if(f==1){
			x++;
			if(x>n) x=n,y++,f=2;
		}
		else{
			x--;
			if(x<1) x=1,y++,f=1;
		}
	}
	printf("%d %d",y,x);
	return 0;
}
/*
ccf is really good,so please to give me 1=.
感觉预期324，可能会高一点
I love ccf!!!!!!!!!!!!
*/
