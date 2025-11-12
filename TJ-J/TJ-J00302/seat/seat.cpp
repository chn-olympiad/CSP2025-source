#include<bits/stdc++.h>

int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,r;
	std::cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)std::cin>>a[i];
	r=a[0];
	for(int i=n*m;i>=1;i--)for(int j=1;j<=i;j++)if(a[j]>a[j-1])std::swap(a[j],a[j-1]);
	for(int i=0;i<n*m;i++)if(a[i]==r)r=i+1;
	if(r%n!=0){
		m=r%n;
		n=(r/n)+1;
		if(n%2!=0)std::cout<<n<<' '<<m;
		else std::cout<<n<<' '<<n-m+1;
	}else{
		m=n;
		n=r/n;
		if(n%2!=0)std::cout<<n<<' '<<m;
		else std::cout<<n<<' '<<1;
	}
	return 0;
} 
