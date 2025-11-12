#include<iostream>
int n;
int a[5001];
long long num;
void f(int i,int maxs,int sum,int c,int zc){
	int m;
	if(a[i]>maxs) m=a[i];
	else m=maxs;
	//num++;
	//std::cout<<i<<' ';
	if(c==0 || i>n) return ;
	if(zc-c+1>2 && sum>2*m){
		 num=(num+1)%998244353;
		 //std::cout<<i<<std::endl;
	} 
	for(int j=i+1;j<=n;j++){
		f(j,m,sum+a[j],c-1,zc);
	} 
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]){
				int b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	for(int i=1;i<=n-3+1;i++){
		f(i,-1,a[i],n-i+1,n-i+1);
	}
	std::cout<<num;
	return 0;
}
