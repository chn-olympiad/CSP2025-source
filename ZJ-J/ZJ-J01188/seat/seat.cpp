#include<bits/stdc++.h>
using namespace std;
int n,m,a,t,s=1;
int c,r,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&t);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a);
		if(a>t)
			s++;
	}
	c=s/n;
	if(s%n!=0){
		f=1;
		r=s-n*c;
		if((c+f)%2==0)
			r=n-r+1;
	}
	else{
		if((c+f)%2==0)
			r=1;
		else
			r=n;
	}
	printf("%d %d\n",c+f,r);
	return 0;
}

