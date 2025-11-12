#include<bits/stdc++.h>
using namespace std;
int n,m,num,f=0;
int x[225];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
	}
	num=x[1];
	sort(x+1,x+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(x[i]==num){
			num=n*m-i+1;
		}
	}
	int y,z,p=1;
	for(int i=1;i<=m;i++){
		if(num<p+n){
			z=i;
			break;
		}
		p+=n;
	}
	if(z%2==0){
		y=n-(num-p);
	}else{
		y=1+(num-p);
	}
	printf("%d %d",z,y);
	return 0;
}
