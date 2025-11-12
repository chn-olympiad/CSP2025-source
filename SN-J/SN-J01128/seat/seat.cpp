//陶家轩 SN-J01128 西安市曲江第一学校 
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
short a[110];
unsigned short n,m;
bool cmp(short x,short y){
	return x>y;
}
void sit(int idx){
	int c,r;
	c=ceil(1.0*idx/n);
	int p=idx%n;
	if(!p) p=n;
	if(c%2){
		r=p;
	}else{
		r=n-p+1; 
	}
	cout<<c<<" "<<r;
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1],idx=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(t==a[i]){
			idx=i;
			sit(idx);
			break;
		}
	}
	return 0;
} 
