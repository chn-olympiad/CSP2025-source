#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],r_w,r_i,yu,shang;
bool cmp(long x,long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==1 && m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	cin>>a[1];
	r_w=a[1];
	for(int i=2;i<=(n*m);i++){
		cin>>a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=(n*m);i++){
		if(a[i]==r_w){
			r_i=i;
			break;
		}
	}
	yu=r_i%(2*n);
	shang=r_i/(2*n);
	if(yu==0){
		cout<< 2*(shang) <<" "<<1;
	}else if(yu>n){
		cout<< 2*(shang+1)<<" "<< n-(yu-n)+1;
	}else if(yu==n){
		cout<< 2*shang+1<<" "<<n;
	}else{
		cout<< 2*shang+1<<" "<< yu;
	}
	return 0;
} 
