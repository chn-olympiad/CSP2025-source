#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int cnt = 0; 
	int n,m;
	int a,b;
	scanf("%d %d",&n,&m);
	int x;
	scanf("%d",&x);
	for(int i = 1;i < n*m;i++){
		int s;
		scanf("%d",&s);
		if(s > x)cnt++;
	}
	a = 1 + (cnt / n);
	if(a % 2 == 1){
		b = 1 + (cnt % n);
	}else{
		b = n - (cnt % n);
	}
	printf("%d %d",a,b);
	return 0;
}
