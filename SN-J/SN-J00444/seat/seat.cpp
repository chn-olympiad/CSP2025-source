#include<bits/stdc++.h>
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		std::cin>>a[i];
	}
	int r=a[1];
	std::sort(a+1,a+1+n*m,cmp);
	double pos;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r) {
			pos=i;
			break;
		}
	}
	int x=ceil(pos/n),y;
	if(x%2==0){
		y=n-(pos-(x-1)*n)+1;
	}
	else{
		y=pos-(x-1)*n;
	}
	std::cout<<x<<" "<<y<<"\n";
	return 0;
}
