//SN-J000754 西安市高新第二初级中学 王昊泽 
#include<bits/stdc++.h>
using namespace std;
int R,n,m,s,a[150],c,r;
bool compare(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	R=a[1];
	sort(a+1,a+n*m+1,compare);
	for(int i=1;i<=n*m;i++){
		s++;
		if(a[i]==R){
			break;
		}
	}
	c=s/n;
	if(s%n!=0){
		c++;
	}
	if(c%2!=0){
		r=s-(n*(c-1));
	}
	else{
		r=1+n-(s-(n*(c-1)));
	}
	printf("%d %d",c,r);
	return 0;
}
