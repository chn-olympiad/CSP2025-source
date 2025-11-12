#include<iostream>
int m,n;
int a[105];
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::cin>>n>>m;
	std::cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		std::cin>>a[i];
	}
//	for(int i=1;i<=n*m;i++){
//		std::cout<<a[i]<<" ";
//	}
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				int b=a[i];
				a[i]=a[j];
				a[j]=b;
//				for(int i=1;i<=n*m;i++){
//					std::cout<<a[i]<<" ";
//				}
//				std::cout<<std::endl;
			}
		}
	}
//	std::cout<<r<<std::endl;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
//	for(int i=1;i<=n*m;i++){
//		std::cout<<a[i]<<" ";
//	}
//	std::cout<<r<<std::endl;
	int lie=(r+n-1)/n;
	int hang;
	if(lie%2==0){
		hang=(n+1)-(r%n==0 ? n : r%n);
	}else{
		hang=(r%n==0 ? n : r%n);
	}
	std::cout<<lie<<" "<<hang;
	return 0;
}
