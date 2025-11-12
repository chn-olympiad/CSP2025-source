#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	int x,t=0,l1=0,l2=0;scanf("%d",&x);
	for(int i=2;i<=n*m;i++){
		int y;scanf("%d",&y);
		if(y>x)t++;
	}
	t++;
	int a1=t%(2*n);
	int a2=t/(2*n);
	if(a1<=n){
		l1=2*a2+1;
		l2=a1;
	}else{
		l1=2*a2+2;
		l2=2*n-a1+1;
	}
	printf("%d %d",l1,l2);
	return 0;
}
