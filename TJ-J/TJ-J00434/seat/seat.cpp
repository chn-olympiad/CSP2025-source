#include<bits/stdc++.h>
using namespace std;
int a[120];
int dk,xk,yk;
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q = n*m;
	for(int i = 1;i <= q;i++){
		cin>>a[i];
	}
	if(m==1&&n==1){
		cout<<"1 1"<<"\n";
		return 0;
	}
	int k = a[1];
	sort(a+1,a+q+1,cmp);
	for(int i = 1;i <= q;i++){
		if(a[i]==k){
			k = i;
			break;
		}
	}
	if(m==1){
		cout<<1<<" "<<k<<"\n";
		return 0;
	}
	if(n==1){
		cout<<k<<" "<<1<<"\n";
		return 0;
	}
	xk = k/n;
	dk = k%n;
	if(xk&1){
		yk = n;
	}else{
		yk = 1;
	}
	if(dk){
		xk += 1;
		dk -= 1;
	}
	if(xk&1){
		yk += dk;
	}else{
		yk -= dk;
	}
	cout<<xk<<" "<<yk<<"\n";
	return 0;
}
