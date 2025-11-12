#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,nb;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(int i = 2; i <= n * m; ++i) {
		scanf("%d",&b);
		if(b > a) ++nb;
	}
	int y = 1,x = 1;
	for(int flag = 0,i = 1; i <= nb; ++i) { //x hang y lie
		if(!flag) { //xia
			if(x == n) ++y,flag = !flag;
			else ++x;
		} else {
			if(x == 1) ++y,flag = !flag;
			else --x;
		}
	}
	printf("%d %d",y,x);
	return 0;
}
