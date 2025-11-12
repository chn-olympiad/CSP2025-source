#include<bits/stdc++.h>
using namespace std;
int n,m,a,cnt;
int f(int x){
	if(x>n)return 2*n-x+1;
	else return x;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1; i<n*m; i++) {
		int x;
		scanf("%d",&x);
		if(x>a)cnt++;
	}
	int mod=(cnt)%(2*n)+1,t=1;
//	cout<<cnt<<' '<<mod<<'\n';
	if(mod>n)t++;
	printf("%d %d",(cnt)/(2*n)*2+t,f(mod));
	return 0;
}
