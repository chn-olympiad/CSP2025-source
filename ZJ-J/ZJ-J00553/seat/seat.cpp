#include<bits/stdc++.h>
int n,m;
int a[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		std::cin>>a[i];
	}
	int xx=a[1],id;
	std::sort(a+1,a+1+n*m,std::greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==xx){
			id=i;
			break;
		}
	}
	int x=id/n;
	int b=id-n*x;
	if(b==0){
		std::cout<<x<<' ';
		if(x%2==0){
			std::cout<<1;
		}else{
			std::cout<<n;
		}
	}else{
		x++;
		std::cout<<x<<' ';
		if(x%2==1) std::cout<<b;
		else std::cout<<n-b+1;
	}
	return 0;
}

