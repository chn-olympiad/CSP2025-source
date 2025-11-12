#include<bits/stdc++.h>
using namespace std;
int n,m,len,a[110],b[110],res,r,c,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	len=n*m;
	for(int i=1;i<=len;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+len);
	res=lower_bound(b+1,b+1+len,a[1])-b;
	res=len-res+1;
	r=(res+n-1)/n;
	t=res%n;
	if(r&1){//ji
		c=t;
		if(t==0) c=n;
	}
	else{//ou
		c=n-t+1;
		if(t==0) c=1;
	}
	printf("%d %d",r,c);
	return 0;
}
