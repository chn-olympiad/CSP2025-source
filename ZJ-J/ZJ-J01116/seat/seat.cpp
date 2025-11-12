#include<iostream>
using namespace std;
int a,other,n,m,s=1;
int w,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;++i){
		cin>>other;
		if(other>a){
			++s;
		}
	}
	w=s/(2*n);
	r=s%(2*n);
	if(1<=r<=n){
		cout<<w*2+1<<" "<<r;
	}else{
		cout<<w*2+2<<" "<<(2*n-r)%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}